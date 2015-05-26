def cal(result, dependencies):
    for dependency in dependencies:
        if result-dependency[0] and dependency[1]-result:
            return cal(result|dependency[1], dependencies)
    return result
dependencies = []
while True:
    dependency = input()
    if dependency == "End":
        break
    dependencies.append([set(i) for i in dependency.split("->")])
while True:
    result = input()
    if result == "End":
        break
    result = cal(set(result),dependencies)
    print("".join(sorted(result)))
