import phonenumbers
from phonenumbers import geocoder


r=input()
ch_number=phonenumbers.parse(r,'CH')
print(geocoder.description_for_number(ch_number,"en"))

from phonenumbers import carrier

service_number=phonenumbers.parse(r,"RO")
print(carrier.name_for_number(service_number,"en"))


