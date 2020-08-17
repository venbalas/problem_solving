logs = ['hbc acd','bjk def','abc def']

def f(log):
    id_,rest = log.split(" ",1)
    return rest,id_

print(sorted(logs, key = f))
