americano_price = 2000
cafelatte_price = 3000
capucine_price = 3500

americano_amount=int(input("아메리카노 판매 개수: "))
cafelatte_amount=int(input("카페라떼 판매 개수: "))
capucine_amount=int(input("카퓨치노 판매 개수: "))

americano_sales_amount = americano_amount*americano_price
cafelatte_sales_amount = cafelatte_amount*cafelatte_price
capucine_sales_amount = capucine_amount*capucine_price

Total_sales_amount = americano_sales_amount + cafelatte_sales_amount + capucine_sales_amount
print("총 매출은 ", Total_sales_amount, "입니다." )