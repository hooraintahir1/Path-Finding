# DECLARE Names : ARRAY [0:9] OF String
Names = [""] * 10
HeadPointer = -1
TailPointer = 0

def Enqueue(data):
    global Names
    global HeadPointer
    global TailPointer

    if TailPointer < 10:
        Names[TailPointer] = data
        TailPointer = TailPointer + 1

        if HeadPointer == -1:
            HeadPointer = 0
    else:
        print("Queue is full")

def Dequeue():
    global Names
    global HeadPointer
    global TailPointer

    if HeadPointer == -1:
        print("Queue is Empty")
    else:
        item = Names[HeadPointer]
        print(item)
        Names[HeadPointer] = ""
        HeadPointer = HeadPointer + 1

    if HeadPointer == TailPointer:
        TailPointer = 0
        HeadPointer = -1

Enqueue("Terminator")
Enqueue("Moeed")
Enqueue("War")
Dequeue()
Enqueue("MrBody")
Dequeue()
Dequeue()
Dequeue()
print(Names)



