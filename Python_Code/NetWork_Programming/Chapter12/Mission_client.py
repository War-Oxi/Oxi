import tkinter.scrolledtext
from tkinter import *
from socket import *
import threading
import struct

def calculate():
    global temp
    # temp = float(entry2.get())
    temp = entry2.get()
    sock.send(str(temp).encode())

def handler(sock):
    while True:
        try:
            r_msg = sock.recv(1024)
        except:
            pass
        else:
            entry2.delete(0,END)
            entry1.insert(tkinter.INSERT, r_msg.decode() + "\n")
            entry1.see(tkinter.END)
            # entry1.delete(0,END)

sock = socket()
sock.connect(("localhost", 2500))

root = Tk()
message_label = Label(text='받은메시지',font=('Verdana', 16))
entry1 = tkinter.scrolledtext.ScrolledText(root, width =20, height= 30, wrap=tkinter.WORD)
entry1.focus_set()
# entry1 = Entry(font=('Verdana', 16), width=10)

recv_label = Label(text="보낼메시지", font=('Verdana', 16))
entry2 = Entry(font=('Verdana', 16), width=20)

calc_button = Button(text='전송', font =('Verdana', 16), command=calculate)

message_label.grid(row=0, column=0, sticky=W)
recv_label.grid(row=1, column=0, sticky=W)
entry1.grid(row=0, column=1)
entry2.grid(row=1, column=1)
calc_button.grid(row=1, column=2, padx=10, pady=10)

cThread = threading.Thread(target=handler, args=(sock,))
cThread.daemon = True
cThread.start()

mainloop()