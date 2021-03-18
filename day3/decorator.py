
def decorate(f):
    def wrapper(a, b):
        result = f(a, b)
        return "<<<<" + result + ">>>>"
    return wrapper

@decorate
def greet(greeting, name):
    return f"{greeting} {name}!"


print(greet("Yo", "Anna"))