/*
Title: hw5_3.cpp
Abstract: This program creates a linear-probing hashtable class to test its methods.
Author: Delaney N.
ID: 1117
Date: 12/6/21
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <limits>

class HashTable
{
	private: 
		int length = 1;
		int numValues = 0;
		double loadFactor = 0;
		int* data = new int[length];
        int hashValue = length;

        bool isPrime(int n)
        {
            //edge cases
            if (n == 0 || n == 1) 
            {
                return false;
            }
            else
            {
                for (int i = 2; i <= n / 2; i++) 
                {
                    if (n % i == 0) 
                    {
                        return false;
                    }
                }
            }
            return true;
        }

        int nextPrime(int n)
        {
            //Bertrand's postulate
            //For any number n > 1, there exists a prime number such that n < p < 2n
            //Run isPrime on all numbers in this range
            for (int i = n; i < 2 * n; i++)
            {
                if (isPrime(i))
                {
                    return i;
                }
            }
        }

        void rehash()
        {
            //temp vector to hold old values
            std::vector<int> temp;
            for (int i = 0; i < length; i++)
            {
                //found data
                if (data[i] != NULL)
                {
                    temp.push_back(data[i]);
                }
            }

            //double data array size and find next prime 
            this->length = nextPrime(length * 2);
            //update hashvalue
            this->hashValue = length;
            //reset numvalues
            this->numValues = 0;
            //resize data array and clear values
            this->data = new int[length];
            //initialize values to null
            for (int i = 0; i < length; i++)
            {
                data[i] = NULL;
            }
            //insert values
            for (int i: temp)
            {
                insert(i);
            }

        }

	public:
		HashTable(int length)
		{
            if (length > 0)
            {
                //ensure length is prime
                this->length = nextPrime(length);
                this->hashValue = this->length;
                this->data = new int[this->length];
                for (int i = 0; i < this->length; i++)
                {
                    data[i] = NULL;
                }
                this->loadFactor = (double)numValues / (double)this->length;
            }
		}

        void insert(int n)
        {
            bool inserted = false;

            //if the space is available, insert
            if (data[n % hashValue] == NULL)
            {
                data[n % hashValue] = n;
                inserted = true;
            }
            //else if the value isn't a duplicate, conduct linear probing
            else if (data[n % hashValue] != n)
            {
                //start at the next value
                int i = (n % hashValue) + 1;

                //count will never reach length due to the load factor not allowing for more than length/2 values at any given time
                //a null value or duplicate value will always be found first
                int count = 0;
                while (count < length)
                {
                    //go back to the beginning
                    if (i == length)
                    {
                        i = 0;
                    }

                    //duplicate value found, we are done
                    if (data[i] == n)
                    {
                        break;
                    }
                    //value was not a duplicate, if it is null then insert
                    else if (data[i] == NULL)
                    {
                        data[i] = n;
                        inserted = true;
                        break;
                    }
                    //else the index is taken and we move on to the next
                    count++;
                    i++;

                }
            }
            if (inserted)
            {
                //increment num values 
                numValues++;
                //recalculate load factor
                loadFactor = (double)numValues / (double)length;
                //rehash if load factor exceeds 0.5
                if (loadFactor > 0.5)
                {
                    rehash();
                }
            }
        }
        void printToConsole()
        {
            for (int i = 0; i < length; i++)
            {
                std::cout << "[" << i << "]: " << data[i] << std::endl;
            }
            std::cout << std::endl;
        }
        void printInfo()
        {
            std::cout << "length: " << this->length << std::endl;
            std::cout << "numValues: " << this->numValues << std::endl;
            std::cout << "load factor: " << this->loadFactor << std::endl;
            std::cout << "hash value: " << this->hashValue << std::endl;
            printToConsole();
        }
        int getSize()
        {
            return this->length;
        }
        double getLoadFactor()
        {
            return this->loadFactor;
        }
        int getNumValues()
        {
            return this->numValues;
        }
        bool hasKey(int key)
        {
            return (getIndex(key) != -1) ? true : false;
        }
        int getIndex(int key)
        {
            //there is data at the index
            if (data[key % hashValue] != NULL)
            {
                //the index has our key
                if (data[key % hashValue] == key)
                {
                    return key % hashValue;
                }
                //our key may be elsewhere
                else
                {
                    //start at the next value
                    int i = (key % hashValue) + 1;

                    //count will never reach length due to the load factor not allowing for more than length/2 values at any given time
                    //a null value or duplicate value will always be found first
                    int count = 0;
                    while (count < length)
                    {
                        //go back to the beginning
                        if (i == length)
                        {
                            i = 0;
                        }

                        //found the key
                        if (data[i] == key)
                        {
                            return i;
                        }
                        //keep searching
                        count++;
                        i++;
                    }
                }
            }
            return -1;
        }
        int getValue(int index)
        {
            if (index < length && index >= 0)
            {
                return (data[index] != NULL) ? data[index] : -1;
            }
            //index was out of bounds
            return -1;
        }
        int* getData()
        {
            return this->data;
        }

};

int main()
{
    int length;
    std::cin >> length;
    while (length < 1)
    {
        std::cout << "Length must be greater than 0\n";
        std::cin >> length;
    }
    
    int numCommands;
    std::cin >> numCommands;
    while (numCommands < 0)
    {
        std::cout << "Number of commands cannot be negative\n";
        std::cin >> numCommands;
    }

    //flush buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::string* commands = new std::string[numCommands];
    for (int i = 0; i < numCommands; i++)
    {
        std::string command;
        //ensure entire command is stored 
        std::getline(std::cin, command);
        commands[i] = command;
    }
    std::cout << std::endl;

    //Do the work
    HashTable hashTable(length);
    for (int i = 0; i < numCommands; i++)
    {
        //again, I would normally map the commands here but since there are only 4 I went with an if else chain
        if (commands[i].substr(0, 6) == "insert")
        {
            //parse the key
            int key = stoi(commands[i].substr(7, commands[i].length() - 7));
            hashTable.insert(key);
        }
        else if (commands[i].substr(0, 13) == "displayStatus")
        {
            //parse the key
            int key = stoi(commands[i].substr(14, commands[i].length() - 14));
            int value = hashTable.getValue(key);
            if (value != -1)
            {
                std::cout << value << std::endl;
            }
            else
            {
                std::cout << "Empty\n";
            }
        }
        else if (commands[i] == "tableSize")
        {
            std::cout << hashTable.getSize() << std::endl;
        }
        else if (commands[i].substr(0, 6) == "search")
        {
            //parse the key
            int key = stoi(commands[i].substr(7, commands[i].length() - 7));
            if (hashTable.hasKey(key))
            {
                std::cout << key << " Found\n";
            }
            else
            {
                std::cout << key << " Not found\n";
            }
        }
    }

    /*int length = 10000;
    HashTable hashTable(length);
    for (int i = 0; i < length; i++)
    {
        int val = rand() % 1000000 + 1;
        hashTable.insert(val);
    }
    hashTable.printInfo();*/
}