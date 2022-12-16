# 12. 아래와 같은 실행결과가 작동되도록 함수를 작성한 파이썬 코드를 제시하시오.
# --------코드-------------
# tico = 자동차("현대", "티코")
# tico.달리다()
# tico.멈추다()
#
# gr = 자동차("현대", "그랜져")
# gr.달리다()
# gr.멈추다()
#
# print( tico )
# print( gr )
#
#
# --------실행결과-------------
# 티코는 달립니다
# 티코는 멈춥니다
# 그랜져는 달립니다
# 그랜져는 멈춥니다
# 자동차 객체입니다.
# 자동차 객체입니다.
class 자동차:
    def __init__(self, manufacturer, carName):
        self.manufacturer = manufacturer
        self.carName = carName
        self.status = False

    def 달리다(self):
        self.status = True
        print(f"{self.carName}은 달립니다")

    def 멈추다(self):
        self.status = False
        print(f"{self.carName}은 멈춥니다")


tico = 자동차("현대", "티코")
tico.달리다()
tico.멈추다()

gr = 자동차("현대", "그랜져")
gr.달리다()
gr.멈추다()

print(tico)
print(gr)

