coin_type = [500, 100, 50, 10, 5, 1]
price = 1000 - int(input())
count = 0

for coin in coin_type:
    count += price//coin
    price %= coin
    
print(count)
