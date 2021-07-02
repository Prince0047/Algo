class Node:   
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    # Insert at Head
    def push(self, data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode

    # Insert at tail
    def append(self, data):
        newNode = Node(data)

        temp = self.head
        while(temp.next!=None):
            temp = temp.next
        
        temp.next = newNode

    def printList(self):
        temp = self.head
        while(temp):
            print(temp.data,end="->")
            temp = temp.next



if __name__ == '__main__':

    Llist = LinkedList()
    Llist.head = Node(0)
    for i in range(5):
        Llist.append(i+1)

    Llist.push(10)
    Llist.printList()
