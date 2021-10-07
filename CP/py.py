str = input()
all_digits = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']

ans = 0
for i in str:
    if i in all_digits:
        ans += 1
print(ans)
