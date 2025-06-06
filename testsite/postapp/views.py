import calendar

from django.db.models import Count, Q
from django.shortcuts import get_object_or_404, render

from .models import Post, PostTag


def get_sidebar_data(is_archive):
    posts = Post.objects.filter(is_archive=is_archive)
    post_timeline = {}
    for post in posts:
        year = str(post.date.year)
        month = str(calendar.month_name[post.date.month])
        if year not in post_timeline:
            post_timeline[year] = {}
        if month not in post_timeline[year]:
            post_timeline[year][month] = []
        post_timeline[year][month].append(post)
    post_timeline = dict(reversed(list(post_timeline.items())))
    tag_list = (
        PostTag.objects.filter(posts__is_archive=is_archive)
        .annotate(num_posts=Count("posts", filter=Q(posts__is_archive=is_archive)))
        .filter(num_posts__gt=0)
        .order_by("-num_posts")
    )
    suggested_posts = Post.objects.filter(
        is_archive=is_archive, suggested=True
    ).order_by("-date")
    return post_timeline, tag_list, suggested_posts


def post_index(request):
    is_archive = request.resolver_match.namespace == "archive"
    posts = Post.objects.filter(is_archive=is_archive).order_by("-date")
    post_timeline, tag_list, suggested_posts = get_sidebar_data(is_archive)
    return render(
        request,
        "postapp/index.html",
        {
            "post_list": posts,
            "post_timeline": post_timeline,
            "tag_list": tag_list,
            "suggested_posts": suggested_posts,
        },
    )


def post_detail(request, slug):
    is_archive = request.resolver_match.namespace == "archive"
    post = get_object_or_404(Post, slug=slug, is_archive=is_archive)
    return render(request, "postapp/detail.html", {"post": post})


def post_tag(request, tag):
    is_archive = request.resolver_match.namespace == "archive"
    tag_obj = get_object_or_404(PostTag, name=tag)
    post_list = Post.objects.filter(tags=tag_obj, is_archive=is_archive).order_by(
        "-date"
    )
    post_timeline, tag_list, suggested_posts = get_sidebar_data(is_archive)
    return render(
        request,
        "postapp/index.html",
        {
            "post_list": post_list,
            "tag_filter": tag_obj,
            "post_timeline": post_timeline,
            "tag_list": tag_list,
            "suggested_posts": suggested_posts,
        },
    )
