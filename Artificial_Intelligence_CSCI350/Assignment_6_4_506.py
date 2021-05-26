#Slot Machine Simulator

import random

startingBalance = 10  #initial number of coins
wheelNumberOne = "X"  #Initial wheel value
wheelNumberTwo = "X"  #Initial wheel value
wheelNumberThree = "X" #Initial wheel value

def isWin(one, two, three):
    """
    isWin takes in the three wheels values from playSlots. 
    If the spin yielded AAA, BBB, CCC, DDD or DD? or D?? you win 
    a specific number of coins. Based on which combination of symbols
    were spun return that win amount based on which combination was 
    spun. If not in the list of combinations return 0
    """
    p = 0  #inital payback is 0 coins
    if (one == "A" and two == "A" and three == "A"):
        p = 80  #if you "spin" an AAA you get 4*20 coins payback
    elif (one == "B" and two == "B" and three == "B"):
        p = 60  #if you "spin" an BBB you get 4*15 coins payback
    elif (one == "C" and two == "C" and three == "C"):
        p = 20  #if you "spin" an CCC you get 4*5 coins payback
    elif (one == "D"):
        if (two == "D" and three == "D"):
            p = 12   #if you "spin" an DDD you get 4*3 coins payback
        elif (two == "D" and three != "D"):
            p = 8    #if you "spin" an DD? you get 4*2 coins payback
        elif (two != "D"):
            p = 4    #if you "spin" an D?? you get 4 coins payback
    #print(p)
    return p #return payback

def playSlots():
    """
    playSlots counts number of plays that occur in one round 
    playing on a slot machine that takes 4 coins as a buy in. 
    """
    payback = startingBalance   #initially make payback startingBalence which is 10
    spinNum = 0                 #set spinNum to 0 (counter var)
    slotChoices = ["A","B","C","D"]  #symbol choices each wheel has
    
    while(payback >= 4):
        payback = payback - 4              
        #to play a round you need to pay 4 coins so delete 4 coins from payback
        wheelNumberOne = random.choice(slotChoices)    #get wheel One's value
        #print("one: ", wheelNumberOne)
        wheelNumberTwo = random.choice(slotChoices)    #get wheel Two's value
        #print("two: ", wheelNumberTwo)
        wheelNumberThree = random.choice(slotChoices)  #get wheel Three's value
        #print("three: ", wheelNumberThree)
        addToPayback = isWin(wheelNumberOne, wheelNumberTwo, wheelNumberThree)
        #send wheel vals to isWin to see whether how many coins you win 
        #print("addToPayback: ", addToPayback)
        payback = payback + addToPayback
        #if you won any coins they will get added to payback var if not then get 0 added
        spinNum = spinNum + 1
        #increment spin Num var to keep track of number of plays
        
    #print("spins: ", spinNum)
    #print("total wins: ", payback)  
    return spinNum  #return spinNum counter variable
        
#s = playSlots() 
#print("total spins", s)

def mean(plist):
    """
    mean takes in a list of spinNums as a parameter and takes the sum of
    all elements in the list and divides it by the number of 
    elements in the list thus returning the average number of plays
    """
    Sum = sum(plist) #sum adds the value of each element in plist
    #print("Sum", Sum)
    avg = Sum/(len(plist)) #ans is the sum divided by number of elements in plist
    return avg   #returns the average number of plays 
    
def median(plist):
    """
    median takes a list of spinNums as a parameter and finds the middle index
    if number of elements in list is odd returns the value in plist with that 
    index. If the number of elements in the list is even like in plist's case 
    since it shouid have 1000 elements it finds the middle two 
    elements in list and takes the average of them and returns that value. 
    """
    l = len(plist)      #assigns num of elements in plist to l(should always be 1000)
    #print(l)
    tlist = sorted(plist)  #sorts plist in order
    if l > 0:  
        i = (l - 1) // 2 #gets middle index
        if (l % 2 != 0):  #odd number of elements in plist
            return tlist[i]
        else:             #even number of elements in plist (should go here)
            return (tlist[i] + tlist[i+1]) / 2.0 #takes average of middle and middle+1 element in plist
        
def playSlots1000():
    """
    playSlots1000 calls playSlots 1000 times and records the number of plays
    each time and prints the median and average of those plays.
    """
    counter = 0              #sets counter to 0
    paybackList = []         #list keeps track of all number of plays
    while (counter < 1000):  #while loop to loop 1000 times
        sn = playSlots()     #calls playSlots
        paybackList.append(sn)  #gets that plays number of plays
        counter = counter + 1   #increments counter
    #print(counter)
    m = mean(paybackList) #calls mean function and gets mean of all the 1000 plays
    me = median(paybackList) #calls median function and gets median of all 1000 plays
    print("mean: ", m, "  median: ", me) #print mean and median

playSlots1000()

#sample mean, median print:
#mean:  44.505   median:  2.0

#After running playSlots1000, the results for median were seemingly always 2, 2.5 or 3, while the mean results were 
#much higher, often ranging from 15 to as high as 80. To expand on the mean values, the reason they are so high is 
#since a handful of times when playing the number of plays would be extremely high, often times reaching 100s
#and sometimes even reaching 1000. The mean is not a great measure of central tendency since every data point
#including the large outliers are being considered. These outliers, although they do not account or reflect 
#the majority of the number of plays, greatly skew the mean. The median on the other hand, since it sorts the
#number of plays in the list and takes the middle one (or average of middle 2) proved to be a much more accurate
#measure of how the common number of plays looked like.

