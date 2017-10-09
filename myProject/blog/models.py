from django.db import models

# Create your models here.

class Post(models.Model):
	name = CharField(max_length=50)
	
	def __str__():
		return "What do you want?"
