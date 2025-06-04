import calendar

from django.db.models import Count
from django.shortcuts import get_object_or_404, render

from .models import Post, PostTag


def get_sidebar_data(is_archive):
    posts = Post.objects.filter(is_archive=is_archive)
    archive_data = {}
    for post in posts:
        year = str(post.date.year)
        month = str(calendar.month_name[post.date.month])
        if year not in archive_data:
            archive_data[year] = {}
        if month not in archive_data[year]:
            archive_data[year][month] = []
        archive_data[year][month].append(post)
    tags = (
        PostTag.objects.annotate(num_posts=Count("posts"))
        .filter(num_posts__gt=0)
        .order_by("-num_posts")
    )
    suggested_posts = Post.objects.filter(
        is_archive=is_archive, suggested=True
    ).order_by("-date")
    return archive_data, tags, suggested_posts


def post_index(request):
    is_archive = request.resolver_match.namespace == "archive"
    posts = Post.objects.filter(is_archive=is_archive).order_by("-date")
    archive_data, tags, suggested_posts = get_sidebar_data(is_archive)
    return render(
        request,
        "postapp/index.html",
        {
            "post_list": posts,
            "archive_data": archive_data,
            "tags": tags,
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
    archive_data, tags, suggested_posts = get_sidebar_data(is_archive)
    return render(
        request,
        "postapp/index.html",
        {
            "post_list": post_list,
            "tag_filter": tag_obj,
            "archive_data": archive_data,
            "tags": tags,
            "suggested_posts": suggested_posts,
        },
    )
