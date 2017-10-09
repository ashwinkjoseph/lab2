from django.shortcuts import render

# Create your views here.

def someView(request):
	return render(request, 'home.html', {})
