import psycopg2
import pygit2

#To print module path

print(dir(pygit2))
print("file",     pygit2.__file__)
print("name ",    pygit2.__name__)
print("package ", pygit2.__package__)
print("path ",    pygit2.__path__)
print("version ", pygit2.__version__)
print("build   ", pygit2._build) 
print("other ",   pygit2._libgit2)
print("discover_repository  ", dir(pygit2.discover_repository))
print("discover_repository  ", help(pygit2.discover_repository))
