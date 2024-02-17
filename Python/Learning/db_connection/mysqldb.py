from mysql.connector import connect, Error
from getpass import getpass

#  user=input("Enter username: "),
# password=getpass("Enter password: ")

def connecting():
     with connect(
        host="localhost",
        user="zakir",
        password="123mysql890"
    ) as connection:
        cursor = connection.cursor()
        cursor.execute("show databases")
        databases = cursor.fetchall() ## it returns a list of all databases present
        ## printing the list of databases
        print(databases)
        ## showing one by one database
        for database in databases:
            print(database)

        print(connection)


if __name__ == '__main__':
    try:
        connecting()
    
    except Error as e:
        print(e)
        exit()


# cursor.execute("show databases")
