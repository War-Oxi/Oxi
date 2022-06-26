americano_price = 2000
cafelatte_price = 3000
capucine_price = 3500

americanos=int(input("아메리카노 판매 개수: "))
cafelattes=int(input("카페라떼 판매 개수: "))
capucines=int(input("카푸치노 판매 개수: "))

sales = americanos*americano_price
sales = sales + cafelattes * cafelatte_price
sales = sales + capucines * capucine_price
print("총 매출은", sales, "입니다")
