import tkinter.scrolledtext
from tkinter import *
from socket import *
import threading
import sys
import struct


def calculate():
    global temp
    temp = entry2.get()
    conn.send(str(temp).encode())
    scrolledtext.insert(tkinter.INSERT, f"Me: {temp} \n")
    scrolledtext.see(tkinter.END)  # 자동으로 스크롤이 내려가도록 하는 함수
    entry2.delete(0, tkinter.END)


def handler(s):
    while True:
        try:
            r_msg = s.recv(1024)
            print(r_msg.decode())
        except:
            pass
        else:
            entry2.delete(0, tkinter.END)
            scrolledtext.insert(tkinter.INSERT, f"받은 메시지: {r_msg.decode()} \n")
            scrolledtext.see(tkinter.END)
            # entry1.delete(0,END)


def keyPressHandler(event):  # 키보드 입력 이벤트를 받기 위한 함수 60행 root.bind 와 연결
    if event.keycode == 13:  # 아스키 코드 38 는 ↑ 키
        calculate()


# global variable
ECHO_PORT = 2500
BUFSIZE = 1024

# main function
if len(sys.argv) > 1:
    port = int(eval(sys.argv[1]))
else:
    port = ECHO_PORT

print(sys.argv)

s = socket(AF_INET, SOCK_STREAM)
s.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
s.bind(('', port))
s.listen(5)
print("Waiting for connection from client")
conn, (remotehost, remoteport) = s.accept()
print('connected by', remotehost, remoteport)

root = Tk()
root.title('server')
# entry1.focus_set()
# entry1 = Entry(font=('Verdana', 16), width=10)


message_label = Label(text='대화 내용', font=('Verdana', 16))
scrolledtext = tkinter.scrolledtext.ScrolledText(root, width=40, height=10, wrap=tkinter.WORD)
recv_label = Label(text="보낼메시지", font=('Verdana', 16))
entry2 = Entry(font=('Verdana', 12), width=25)
calc_button = Button(text='전송', font=('Verdana', 16), command=calculate)

message_label.grid(row=0, column=0, sticky=W)
recv_label.grid(row=1, column=0, sticky=W)
scrolledtext.grid(row=0, column=1)
entry2.grid(row=1, column=1)
calc_button.grid(row=1, column=2, padx=10, pady=10)

cThread = threading.Thread(target=handler, args=(conn,))
cThread.daemon = True
cThread.start()

root.bind("<KeyPress>", keyPressHandler)  ##키보드 입력 이벤트 발생시 keyPressHandler함수 호출

root.mainloop()  # 윈도우 창을 윈도우가 종료될 때 까지 실행
