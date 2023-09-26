#Huffman coding is used to compress text file without losing any data
#character are transmitted in a text file in ascii code format which is of 8 bit fixed length,
#it isn't efficent way of storing text as some letters (eg: e, t) occur more frequently than others,
#if we are able to use variable size bit length than text files can be stored in a disk occupying minimal space.
#However, the problem with variable size bit length is computers generally do not have a way of delimetering bit string,
#For example, if we use 001 to denote 'e', 0 to denote a whitespace, and 1 to interpret letter 'a' and given a bit string
#001001 computers cannot differentiate if its 'ee' or e followed by two space and a ('e  a') or if it's ('  ae')

#Huffman coding is a compression technique which counts the frequency of the characters that appears in the text file,
#it then sorts the character based on the frequency, removes the two minimum elements and then store them in a tree with their frequency as
#the root. 


#creating Trees

class Tree(object):
    def __init__(self, left=None, right=None, value = None, frequency = 0):
        self.left = left
        self.right = right
        self.value = value
        self.frequency = frequency

    def children(self):
        return (self.left, self.right)
    
    def nodes(self):
        return (self.left, self.right)
    
    def value_sum(self):
        return (self.value, self.frequency)


#counting frequency:
def count_frequency(string):
    count = {}

    for s in string:
        if s in count.keys():
            count[s] += 1
        else:
            count[s] = 1
    
    return sorted(count.items(), key= lambda x: x[1])

#convert each letter into a tree and append the tree to a list
def create_tree_list(freq_table):
    tree_ = []
    for s in freq_table:
        s = Tree(value=s[0], frequency=s[1])
        tree_.append(s)
    return tree_


#inserting the newly formed tree to the list of tree
def insert(A, s):
    i = 0
    while i < len(A) and s.frequency > A[i].frequency:
        i += 1
    A.insert(i, s)


freq_table = count_frequency('aaabbccd')
tree_ = create_tree_list(freq_table)

while len(tree_) > 1:
    first_tree = tree_[0]
    second_tree = tree_[1]
    tree_ = tree_[2:]
    new_tree = Tree(left=first_tree, right=second_tree, value=None, frequency = first_tree.frequency + second_tree.frequency)
    insert(tree_, new_tree)
    print(len(tree_), new_tree.frequency)

final_tree = tree_[0]


    

