import random
import argparse

parser = argparse.ArgumentParser(description='Automatic sampler creator.')
parser.add_argument('--output','-o', default='output', help='Name of the output file. ex: "-o out" creates a file called "out.txt"')
parser.add_argument('-n', '--quantity', default=100, type=int, help='Quantity of number to be randomically generated (default is 100)')
args = parser.parse_args()
print("{} numbers to {}.txt".format(args.quantity, args.output))

arq = open(args.output+'.txt', 'w')
for n in random.sample(range(args.quantity), args.quantity):
	arq.write("{}\n".format(n))

print("DONE {}!".format(args.quantity))
