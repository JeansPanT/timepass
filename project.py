import mysql.connector

myobj=mysql.connector.connect(host="localhost",user="root",passwd="root",database="bank") 

if myobj.connect:              
    print("connected")                                                                
else:
    print("data base problem")
    
myc=myobj.cursor()            


def Creation():
    
    sacc=input("Enter your name seperately with _ : ") 

    Table="CREATE TABLE IF NOT EXISTS {} (cid VARCHAR(20), cno VARCHAR(20), adds VARCHAR(20), sbal INT, cr INT, dr INT, dot DATE)"\
            .format(sacc)       

    myc.execute(Table)                   
    


    scid=int(input("Enter the Customer ID : "))
    scno=int(input("Enter your Contact Number : "))
    sadds=input("Enter your Current Address : ")
    sbal=int(input("Enter Initial Amount to be deposited : "))
    
    
    
    st="insert into  {} (cid,cno,adds,sbal) VALUES(%s,%s,%s,%s)".\
        format(sacc)                         

        
    val=(scid,scno,sadds,sbal)
    
    myc.execute(st,val)           
    
    myc.execute("COMMIT")         

        
    print("\n Press any key to continue")      
    ch=input()                       
   
   
    
def Dispacc():

    sacc=input("Enter your name seperately with _ : ")    
                                                                

    myc.execute("SHOW TABLES")     
    
    
    data=myc.fetchall()            
    

    for i in data:                 
        if sacc in i:
            print("table exists")
            break
    
    else:
        print("table does not exist") 
        return
    
    
    myc.execute("SELECT * FROM {}".format(sacc))  
    
    data=myc.fetchall()                       
    
    
    
    
    print('-'*150)                         
    
    
    print("| {0:10}".format('Customer ID'),end="") 
    print("| {0:20}".format('Contact No'),end="")
    print("| {0:20}".format('Address'),end="")
    print("| {0:20}".format('Balance'),end="")
    print("| {0:20}".format('Credit'),end="")
    print("| {0:20}".format('Debit'),end="|\n")
    

   
    print('-'*150)       


    for i in data:
        print("| {0:10}".format(i[0]),end="")    
        print("| {0:20}".format(i[1]),end="")
        print("| {0:20}".format(i[2]),end="")
        print("| {0:20}".format(i[3]),end="")
        print("| {0:20}".format(i[4]),end="")
        print("| {0:20}".format(i[5]),end="|\n")
        
    print('-'*150)                           
    
    print()
    print("\n Press any key to continue")
    ch=input()                             
      
   
 
    


def Updacc():
    
    sacc=input("Enter your name seperately with _ : ")  
    
    scid=input("Enter the Customer ID :")    

    myc.execute("SHOW TABLES")     
    
    
    data=myc.fetchall()            
    

    for i in data:                 
        if sacc in i:
            print("table exists")
            break
    
    else:
        print("table does not exist")  
        return
    
    
   
    
    st="SELECT * FROM {} WHERE cid='{}'".format(sacc,scid)

   
    myc.execute(st)    
    
    data=myc.fetchall() 
    
    if data:
        print("Your Account's details are :\n") 

        
        
        
        print('-'*130)                       
    
    
        print("| {0:20}".format('Customer ID'),end="")  
        print("| {0:20}".format('Contact No'),end="")
        print("| {0:20}".format('Address'),end="|\n")
    

    
        print('-'*130)       


        for i in data:
            print("| {0:20}".format(i[0]),end="")   
            print("| {0:20}".format(i[1]),end="")
            print("| {0:20}".format(i[2]),end="|\n")
        
        print('-'*130)                          
    
        print("\n Press any key to continue")
        ch=input()
       

        
        
        print()
        print(" 1.Modify Customer ID\n")
        print(" 2.Modify Contact No.\n")
        print(" 3.Modify Address\n")
        
                
        choice=int(input("Enter Your Choice  "))   

        new=" "                      

        
        if choice==1:
            field='cid'        
            
        elif choice==2:
            field='cno'
            
        elif choice==3:
            field='adds'
              
                   
        new=input("Enter the new data :  ")     

        
            
        st="UPDATE {} SET {}='{}' WHERE cid ='{}'".format(sacc,field,new,scid)
        
        myc.execute(st)        
        
        myc.execute("COMMIT")  
        
        print("\nRecord Updated")
    
                 
    else:
        print("\n Data not found" )     
        

    print("\n Press any key to continue")
    ch=input()
    
def Depmoney () :

    sacc=input("Enter the Firstname and Surname seperated by __ : ") 
    Table="CREATE TABLE IF NOT EXISTS {} (cid VARCHAR(20), cno VARCHAR(20), adds VARCHAR(40), sbal INT, cr INT, dr INT, dot DATE)"\
            .format(sacc)       

    myc.execute(Table)   



    cid=int(input("Enter the Customer ID :  "))      
    depo=int(input("\n Enter the amount you wish to deposit : "))
    dat=input("Enter the Date of transaction :")
    
    
    st="UPDATE {} SET sbal=sbal+'{}' WHERE cid ='{}'".format(sacc,depo,cid)
    sn="UPDATE {} SET cr='{}' WHERE cid ='{}'".format(sacc,depo,cid)
    sg="UPDATE {} SET dot='{}' WHERE cid ='{}'".format(sacc,dat,cid)
    
    
    myc.execute(st)
    myc.execute(sn)
    myc.execute(sg)
    
    myc.execute("COMMIT")  
    
    print("\n Money has been deposited Successfully !")

    
    print("\n Press any key to continue")
    ch=input()
    
 

#withdrawal  
    
def Withdmoney () :
    
    sacc=input("Enter the Firstname and Surname seperated by __ : ") 
    Table="CREATE TABLE IF NOT EXISTS {} (cid VARCHAR(20), cno VARCHAR(20), adds VARCHAR(40), sbal INT, cr INT, dr INT, dot DATE)"\
            .format(sacc)       

    myc.execute(Table)   

    cid=int(input("Enter the Customer ID :  "))      
    depo=int(input("\n Enter the amount you wish to withdraw : "))
    dat=input("Enter the Date of transaction :")
    
    
    st="UPDATE {} SET sbal=sbal-'{}' WHERE cid ='{}'".format(sacc,depo,cid)
    sn="UPDATE {} SET dr='{}' WHERE cid ='{}'".format(sacc,depo,cid)
    sg="UPDATE {} SET dot='{}' WHERE cid ='{}'".format(sacc,dat,cid)
    
    myc.execute(st)
    myc.execute(sn)
    myc.execute(sg)
    
    myc.execute("COMMIT")  
    
    print("\n Money has been deposited Successfully !")

    
    print("\n Press any key to continue")
    ch=input()
   

    
# balance

def Balance():
    sacc=input("Enter the Firstname and Surname seperately by __ : ") 

    myc.execute("SHOW TABLES")     
    
    data=myc.fetchall()            
    

    for i in data:                 
        if sacc in i:
            print("table exists")
            break
    
    else:
        print("table does not exist")  
        return

    
    cid=input("Enter the Customer ID :  ")
  
    st="SELECT sbal,dot FROM {}".format(sacc,cid)
    myc.execute(st)
    data=myc.fetchall()
    if data:
        print("Your current balance is:",data)
    else:
        print("Record Not Found , Please Try Again !")
        
 #Delete Data
        
def Dltacc():

    sacc=input("Enter the Firstname and Surname seperated by _: ")    
                                                                    
    cid=input("Enter the Customer :")     

    myc.execute("SHOW TABLES")     
    
    data=myc.fetchall()           

    for i in data:                 
        if sacc in i:
            print("table exists")
            break
    
    else:
        print("table does not exist")  
        return
    
     
    myc.execute("DELETE FROM {} WHERE cid='{}' ".format(sacc,cid ))
  
    
    myc.execute("COMMIT")  
        
    print("\nRecord DELETED")
    


def firstpage():
    project="BANK ACCOUNT MANAGEMENT SYSTEM"
    space=' '
    
    print("\n"*45)
    print(space*0+'*'*46)
    space=' '
    print(space*0+'*'+space*7+project+space*7+'*')
    print(space*0+'*'*46)

    
    print("\n"*4)
    print(space*0+"Prepared by :")
    print(space*14+"_______________\n")
    print(space*14+"_______________\n")
    
    print("Press any key to continue".center(125))
    ch=input()  
    

#MAIN PROGRAM

firstpage()

print("="*60)
print("\n")

while(1):
    print("\n")
    print("="*48)
    print("|                                              |")
    print("|   1. Create an Account                       |")
    print("|   2. Update Account details                  |")
    print("|   3. Deposit Money                           |")					
    print("|   4. Withdraw Money                          |")
    print("|   5. Check Account Balance                   |")
    print("|   6. Display Passbook                        |")
    print("|   7. Delete an Account                       |")
    print("|   8. Exit                                    |")
    print("|                                              |")
    print("="*48)
    print("\n")
    
    	               
    choice=int(input("Enter your Choice :  "))
    print()
    if choice==1:
        Creation()
    elif choice==6:
        Dispacc()
    elif choice==2:
        Updacc()
    elif choice==3:
        Depmoney()
    elif choice==4:
        Withdmoney()
    elif choice==5:
        Balance()
    elif choice==7:
        Dltacc()
    elif choice==8:
        
        print("you are out of project")
        break
    else:
        print("Sorry ,wrong choice.Press any key to exit")
        ch=input()
        break
myc.close()