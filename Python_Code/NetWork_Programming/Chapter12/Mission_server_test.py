import tkinter.scrolledtext
from tkinter import *
from socket import *
import threading
import sys
import struct

def calculate():
    global temp
    # temp = float(entry2.get())
    temp = entry2.get()
    conn.send(str(temp).encode())
    entry2.delete(0, END)



def handler(s):
    while True:
        try:
            r_msg = s.recv(1024)
            print(r_msg.decode())
        except:
            pass
        else:
            entry2.delete(0,END)
            entry1.insert(tkinter.INSERT, r_msg.decode() + "\n")
            entry1.see(tkinter.END)
            # entry1.delete(0,END)

ECHO_PORT = 2500
BUFSIZE = 1024

if len(sys.argv) > 1:
    port = int(eval(sys.argv[1]))
else:
    port = ECHO_PORT

s = socket()
s.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
s.bind(('', port))
s.listen(5)

print("Waiting for connection from client")
conn, (remotehost, remoteport) = s.accept()
print('connected by', remotehost, remoteport)

root = Tk()
root.title('server')
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

cThread = threading.Thread(target=handler, args=(conn,))
cThread.daemon = True
cThread.start()

mainloop()