from django.db import models
from django.utils import timezone


class PostTag(models.Model):
    def __str__(self):
        return self.name

    name = models.CharField(max_length=50, unique=True)


class Post(models.Model):
    def __str__(self):
        return self.title

    title = models.CharField(max_length=200)
    slug = models.SlugField(unique=True, null=False, blank=False, max_length=200)
    is_archive = models.BooleanField(default=False)
    suggested = models.BooleanField(default=False)
    date = models.DateField(default=timezone.now)
    tags = models.ManyToManyField(PostTag, related_name="posts")
