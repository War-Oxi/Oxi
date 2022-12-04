import tkinter.scrolledtext
from tkinter import *
from socket import *
import threading
import struct


def calculate():
    global temp
    temp = entry2.get()
    sock.send(str(temp).encode())
    entry1.insert(tkinter.INSERT, f"Me: {temp} \n")
    entry1.see(tkinter.END)
    entry2.delete(0, END)


def handler(sock):
    while True:
        try:
            r_msg = sock.recv(1024)
            print(r_msg.decode())
        except:
            pass
        else:
            entry2.delete(0, END)
            entry1.insert(tkinter.INSERT, f"받은 메시지: {r_msg.decode()} \n")
            entry1.see(tkinter.END)
            # entry1.delete(0,END)


def keyPressHandler(event):  # 키보드입력 이벤트를 받기 위한 함수 60행 root.bind와 연결
    if event.keycode == 13:  # 아스키코드 38 는 ↑ 키
        calculate()


sock = socket()
sock.connect(("localhost", 2500))

root = Tk()
root.title('client')
message_label = Label(text='대화 내용', font=('Verdana', 16))
recv_label = Label(text="보낼메시지", font=('Verdana', 16))
entry1 = tkinter.scrolledtext.ScrolledText(root, width=40, height=10, wrap=tkinter.WORD)
entry2 = Entry(font=('Verdana', 12), width=25)
calc_button = Button(text='전송', font=('Verdana', 16), command=calculate)
# entry1.focus_set()
# entry1 = Entry(font=('Verdana', 16), width=10)

message_label.grid(row=0, column=0, sticky=W)
recv_label.grid(row=1, column=0, sticky=W)
entry1.grid(row=0, column=1)
entry2.grid(row=1, column=1)
calc_button.grid(row=1, column=2, padx=10, pady=10)

cThread = threading.Thread(target=handler, args=(sock,))
cThread.daemon = True
cThread.start()

root.bind("<KeyPress>", keyPressHandler)  # 키보드 입력 이벤트 발생시 keyPressHandler함수 호출

mainloop()
