import re


class hashTable:
    def __init__(self):
        self.size = int(input("Enter the size of hash table: "))
        self.table = list(None for i in range(self.size))
        self.elementCounts = 0
        self.comparisons = 0

    def hashFunc(self, key):
        return key % self.size

    def isFull(self):
        if self.elementCounts == self.size:
            return True
        else:
            return False

    def get_number(self, key):
        re.findall(r'\d+', "{}".format(key))

    def insert(self, record):
        if self.isFull():
            print("Hash table is Full")
            return False

        isStored = False

        pos = self.hashFunc(self.get_number(record))
        # checking if the position is empty

        if self.table[pos] == None:
            self.table[pos] = record
            print("phone number is at position: ", str(pos))
            isStored = True
            self.elementCounts += 1

        # for collision doing linear probing
        else:
            print("collsion has occured at postion: ", str(pos))
            while self.table[pos] != None:
                pos += 1
                if pos >= self.size:
                    pos = 0

            self.table[pos] = record
            isStored = True
            self.elementCounts += 1

        return isStored

    def search(self, record):
        # returns position of element if found
        # else returns False
        found = False
        pos = self.hashFunc(self.get_number(record))
        self.comparisons += 1

        if(self.table[pos] == self.get_number(record)):
            isfound = True
            print("Record found at position ", pos, " takes ",
                  self.comparisons, " no. of comparisons")
            return pos

        else:
            isfound = False
            print("Record does'nt match")
            return False

    def display(self):
        print("\n")
        for i in range(self.size):
            print("Hash Value: "+str(i) + "\t\t" + str(self.table[i]))
        print("The number of records in the Table are : " + str(self.elementCounts))


Ht = hashTable()
