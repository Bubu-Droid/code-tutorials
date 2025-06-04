from django.urls import path

from . import views

app_name = "postapp"
urlpatterns = [
    path("", views.post_index, name="post_index"),
    path("<slug:slug>/", views.post_detail, name="post_detail"),
    path("tag/<str:tag>/", views.post_tag, name="post_tag"),
]
