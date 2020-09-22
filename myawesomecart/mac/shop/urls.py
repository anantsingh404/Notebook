from django.urls import path
from .import views
urlpatterns = [
    path("", views.index, name="shop home"),
    path("about/", views.about, name="about us"),
    path("contact/", views.contact, name="contact us"),
    path("tracker/", views.tracker, name="tracking status"),
    path("search/", views.search, name="search"),
    path("productview/", views.productview, name="product view"),
    path("checkout/", views.checkout, name="checkout")
]