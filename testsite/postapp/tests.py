from django.test import TestCase
from django.urls import reverse

from .models import Post, PostTag


def create_post(title, slug, tags=None, is_archive=False):
    """Utility function to create a Post object with optional tags and archive flag."""
    post = Post.objects.create(title=title, slug=slug, is_archive=is_archive)
    if tags:
        post.tags.set(tags)
    return post


class PostViewTests(TestCase):
    def setUp(self):
        """Create reusable tags for tests."""
        self.tag_math = PostTag.objects.create(name="math")
        self.tag_cs = PostTag.objects.create(name="cs")

    def run_index_tests(self, namespace, is_archive):
        """Test the index view shows correct posts based on archive flag and namespace."""
        response = self.client.get(reverse(f"{namespace}:post_index"))
        self.assertContains(response, "No posts yet!")
        self.assertQuerySetEqual(response.context["post_list"], [])

        post1 = create_post(
            "Post A", "post-a", tags=[self.tag_math], is_archive=is_archive
        )
        post2 = create_post(
            "Post B", "post-b", tags=[self.tag_cs], is_archive=is_archive
        )

        response = self.client.get(reverse(f"{namespace}:post_index"))
        self.assertContains(response, "Post A")
        self.assertContains(response, "Post B")
        self.assertContains(response, "math")
        self.assertContains(response, "cs")
        self.assertIn("archive_data", response.context)
        self.assertIn("tags", response.context)
        self.assertGreater(len(response.context["tags"]), 0)

    def run_detail_tests(self, namespace, is_archive):
        """Test the detail view renders the post and rejects if namespace is wrong."""
        post = create_post(
            "Detailed Post", "detailed", tags=[self.tag_math], is_archive=is_archive
        )

        response = self.client.get(
            reverse(f"{namespace}:post_detail", args=[post.slug])
        )
        self.assertContains(response, "Detailed Post")
        self.assertEqual(response.context["post"], post)

        wrong_ns = "archive" if namespace == "blog" else "blog"
        wrong_response = self.client.get(
            reverse(f"{wrong_ns}:post_detail", args=[post.slug])
        )
        self.assertEqual(wrong_response.status_code, 404)

    def run_tag_filter_test(self, namespace, is_archive):
        """Test tag filtering view includes correct posts based on tag and archive flag."""
        tagged = create_post(
            "Tagged Post", "tagged-post", tags=[self.tag_math], is_archive=is_archive
        )
        untagged = create_post(
            "Untagged Post", "untagged", tags=[self.tag_cs], is_archive=is_archive
        )

        url = reverse(f"{namespace}:post_tag", args=[self.tag_math.name])
        response = self.client.get(url)
        self.assertContains(response, "Tagged Post")
        self.assertEqual(response.context["tag_filter"], self.tag_math)
        self.assertIn("archive_data", response.context)
        self.assertIn("tags", response.context)

    def run_tag_filter_exclusion_test(self, namespace, is_archive):
        """Ensure posts not matching the tag are excluded from tag-filtered view."""

        Post.objects.all().delete()

        create_post(
            "Should Appear", "appear", tags=[self.tag_math], is_archive=is_archive
        )
        create_post(
            "Should Not Appear", "hide", tags=[self.tag_cs], is_archive=is_archive
        )

        url = reverse(f"{namespace}:post_tag", args=[self.tag_math.name])
        response = self.client.get(url)
        self.assertContains(response, "Should Appear")
        self.assertNotContains(response, "Should Not Appear")

    def run_slug_edge_case_test(self, namespace, is_archive):
        """Ensure slug with hyphens and numbers works correctly."""
        post = create_post(
            "INMO 2022 Review", "inmo-2022-review", is_archive=is_archive
        )
        url = reverse(f"{namespace}:post_detail", args=["inmo-2022-review"])
        response = self.client.get(url)
        self.assertEqual(response.status_code, 200)
        self.assertContains(response, "INMO 2022 Review")

    def test_blog_views(self):
        """Run index, detail, tag, exclusion, and slug tests for blog section."""
        self.run_index_tests("blog", is_archive=False)
        self.run_detail_tests("blog", is_archive=False)
        self.run_tag_filter_test("blog", is_archive=False)
        self.run_tag_filter_exclusion_test("blog", is_archive=False)
        self.run_slug_edge_case_test("blog", is_archive=False)

    def test_archive_views(self):
        """Run index, detail, tag, exclusion, and slug tests for archive section."""
        self.run_index_tests("archive", is_archive=True)
        self.run_detail_tests("archive", is_archive=True)
        self.run_tag_filter_test("archive", is_archive=True)
        self.run_tag_filter_exclusion_test("archive", is_archive=True)
        self.run_slug_edge_case_test("archive", is_archive=True)

    def test_sidebar_tag_counts(self):
        """Test that tag counts in sidebar match post associations."""
        create_post("Tagged Once", "once", tags=[self.tag_math])
        create_post("Tagged Twice", "twice", tags=[self.tag_math, self.tag_cs])

        response = self.client.get(reverse("blog:post_index"))
        tags = response.context["tags"]

        math_tag = next(t for t in tags if t.name == "math")
        cs_tag = next(t for t in tags if t.name == "cs")

        self.assertEqual(math_tag.num_posts, 2)
        self.assertEqual(cs_tag.num_posts, 1)


def test_tag_isolation_between_namespaces(self):
    """Tags used only in blog or archive should not appear in the other sidebar."""
    # Blog post with math tag
    create_post("Blog Post", "blog-post", tags=[self.tag_math], is_archive=False)

    # Archive post with cs tag
    create_post("Archive Post", "archive-post", tags=[self.tag_cs], is_archive=True)

    # Check blog: only math should appear
    blog_response = self.client.get(reverse("blog:post_index"))
    blog_tags = blog_response.context["tags"]
    blog_tag_names = {t.name for t in blog_tags}
    self.assertIn("math", blog_tag_names)
    self.assertNotIn("cs", blog_tag_names)

    # Check archive: only cs should appear
    archive_response = self.client.get(reverse("archive:post_index"))
    archive_tags = archive_response.context["tags"]
    archive_tag_names = {t.name for t in archive_tags}
    self.assertIn("cs", archive_tag_names)
    self.assertNotIn("math", archive_tag_names)


def test_post_index_isolation_between_namespaces(self):
    """Posts should appear only in their designated namespace (blog/archive)."""
    blog_post = create_post("Blog Post", "blog-post", is_archive=False)
    archive_post = create_post("Archive Post", "archive-post", is_archive=True)

    blog_response = self.client.get(reverse("blog:post_index"))
    archive_response = self.client.get(reverse("archive:post_index"))

    self.assertContains(blog_response, "Blog Post")
    self.assertNotContains(blog_response, "Archive Post")

    self.assertContains(archive_response, "Archive Post")
    self.assertNotContains(archive_response, "Blog Post")


def test_archive_data_isolation_between_namespaces(self):
    """archive_data should only contain posts from the correct namespace."""
    blog_post = create_post("Blog Post", "blog-post", is_archive=False)
    archive_post = create_post("Archive Post", "archive-post", is_archive=True)

    blog_response = self.client.get(reverse("blog:post_index"))
    archive_response = self.client.get(reverse("archive:post_index"))

    blog_archive_data = blog_response.context["archive_data"]
    archive_archive_data = archive_response.context["archive_data"]

    # Flatten to list of titles for easier testing
    blog_titles = [
        post.title
        for year in blog_archive_data.values()
        for month_posts in year.values()
        for post in month_posts
    ]

    archive_titles = [
        post.title
        for year in archive_archive_data.values()
        for month_posts in year.values()
        for post in month_posts
    ]

    self.assertIn("Blog Post", blog_titles)
    self.assertNotIn("Archive Post", blog_titles)

    self.assertIn("Archive Post", archive_titles)
    self.assertNotIn("Blog Post", archive_titles)


class SuggestedPostsTest(TestCase):
    def setUp(self):
        # Create blog post
        self.blog_post = Post.objects.create(
            title="Blog Post",
            slug="blog-post",
            is_archive=False,
            suggested=True,
        )

        # Create archive post
        self.archive_post = Post.objects.create(
            title="Archive Post",
            slug="archive-post",
            is_archive=True,
            suggested=True,
        )

        # Create non-suggested post
        self.normal_post = Post.objects.create(
            title="Normal Post",
            slug="normal-post",
            is_archive=False,
            suggested=False,
        )

    def test_suggested_posts_on_blog_page(self):
        response = self.client.get(reverse("blog:post_index"))
        self.assertContains(response, "Blog Post")
        self.assertNotContains(response, "Archive Post")
        self.assertContains(response, "Normal Post")

    def test_suggested_posts_on_archive_page(self):
        response = self.client.get(reverse("archive:post_index"))
        self.assertContains(response, "Archive Post")
        self.assertNotContains(response, "Blog Post")
        self.assertContains(response, "Normal Post")

    def test_suggested_section_only_appears_when_needed(self):
        response = self.client.get(reverse("blog:post_index"))
        self.assertContains(response, "Suggested Reads")

        # Turn off suggestions
        self.blog_post.suggested = False
        self.blog_post.save()

        response = self.client.get(reverse("blog:post_index"))
        self.assertNotContains(response, "Suggested Reads")


class SidebarVisibilityTest(TestCase):
    def test_sidebar_hidden_when_no_content(self):
        response = self.client.get(reverse("blog:post_index"))
        html = response.content.decode()

        self.assertNotIn("Archives", html)
        self.assertNotIn("Tags", html)
        self.assertNotIn("Suggested Reads", html)

    def test_timeline_shows_up_when_posts_exist(self):
        Post.objects.create(
            title="Some Post",
            slug="some-post",
            is_archive=False,
            suggested=False,
        )
        response = self.client.get(reverse("blog:post_index"))
        self.assertContains(response, "Archives")

    def test_tags_box_only_shows_if_tags_exist(self):
        tag = PostTag.objects.create(name="math")
        post = Post.objects.create(
            title="Tagged Post",
            slug="tagged-post",
            is_archive=False,
            suggested=False,
        )
        post.tags.add(tag)

        response = self.client.get(reverse("blog:post_index"))
        self.assertContains(response, "Tags")
        self.assertContains(response, "math")

    def test_suggested_box_only_shows_if_something_is_suggested(self):
        Post.objects.create(
            title="Suggested Post",
            slug="suggested-post",
            is_archive=False,
            suggested=True,
        )
        response = self.client.get(reverse("blog:post_index"))
        self.assertContains(response, "Suggested Reads")

    def test_suggested_box_hidden_if_no_suggestions(self):
        Post.objects.create(
            title="Normal Post",
            slug="normal-post",
            is_archive=False,
            suggested=False,
        )
        response = self.client.get(reverse("blog:post_index"))
        self.assertNotContains(response, "Suggested Reads")


def test_suggested_post_appears_in_post_list(self):
    suggested_post = Post.objects.create(
        title="Featured",
        slug="featured",
        is_archive=False,
        suggested=True,
    )
    response = self.client.get(reverse("blog:post_index"))
    self.assertIn(suggested_post, response.context["post_list"])


def test_tag_filter_sidebar_only_shows_namespace_tags(self):
    tag1 = PostTag.objects.create(name="A")
    tag2 = PostTag.objects.create(name="B")

    create_post("Post A", "a", tags=[tag1], is_archive=False)
    create_post("Post B", "b", tags=[tag2], is_archive=True)

    response = self.client.get(reverse("blog:post_tag", args=["A"]))
    tag_names = {tag.name for tag in response.context["tags"]}
    self.assertIn("A", tag_names)
    self.assertNotIn("B", tag_names)


def test_tags_not_shown_if_not_attached(self):
    tag = PostTag.objects.create(name="floating")
    # no post attached

    response = self.client.get(reverse("blog:post_index"))
    self.assertNotContains(response, "floating")
    self.assertNotContains(response, "Tags")
