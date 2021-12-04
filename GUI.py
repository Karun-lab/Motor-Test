import serial
import time

arduino = serial.Serial(port = 'COM12', timeout=0) #Change the COM Port according to your Connection
time.sleep(2)

from tkinter import*
w =Tk()
w.geometry('300x300')
w.configure(bg="#141414")
def bttn(x,y,text,bcolor,fcolor,cmd):

     def on_enter(e):
         mybutton['background']= bcolor
         mybutton['foreground']= fcolor

     def on_leave(e):
         mybutton['background']=fcolor
         mybutton['foreground']=bcolor

     mybutton= Button(w,width=42, height=2, text=text,
                       fg=bcolor,
                       bg=fcolor,
                       border=0,
                       activeforeground=fcolor,
                       activebackground=bcolor,
                       command=cmd,)


     mybutton.bind("<Enter>", on_enter)
     mybutton.bind("<Leave>", on_leave)
     mybutton.place(x=x,y=y)

def cmd():
  print("0")
  arduino.write(str.encode('0'))

def cmd1():
  print("1")
  arduino.write(str.encode('1'))

def cmd2():
  print("2")
  arduino.write(str.encode('2'))

def cmd3():
  print("3")
  arduino.write(str.encode('3'))

def cmd4():
  print("4")
  arduino.write(str.encode('4'))



bttn(0,0,"STOP",'#f86263',"#141414",cmd)
bttn(0,37,"Motor 1",'#25dae9',"#141414",cmd1)
bttn(0,74,"Motor 2",'#25dae9',"#141414",cmd2)
bttn(0,110,"Motor 3",'#25dae9',"#141414",cmd3)
bttn(0,147,"All At Once",'#ffa157',"#141414",cmd4)
w.mainloop()
