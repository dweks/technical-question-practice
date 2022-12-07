package main

import (
	"fmt"
	"bufio"
	"os"
)

type Node struct {
	char byte
	dit *Node
	dah *Node
}

func main() {
	var root Node
	var ditChar = '.'
	var dahChar = '-'
	var space = '|'
	var word = '/'
	var response = 'n'
	testInput := "-...|.-..|.-|-.-|./..|.../....|.-|-.|-..|...|---|--|.|"

	if len(os.Args[1:]) != 0 {
		testInput = os.Args[1]
	}

	buildTree(&root)

	fmt.Println("-DAH .DIT")

	fmt.Print("Customize? y/n: ")
	readChar(&response)

	if response == 'y' {
		fmt.Print("Choose a dah: ")
		readChar(&dahChar)
		fmt.Print("Choose a dit: ")
		readChar(&ditChar)
		fmt.Print("Choose a space: ")
		readChar(&space)
		fmt.Print("Choose a word: ")
		readChar(&word)
	}

	var current *Node = &root

	for _, char := range testInput {
		switch char {
			case ditChar:
				current = current.dit
			case dahChar:
				current = current.dah
			case space:
				if current == nil || current.char == 0 {
					current = &root
				} else {
					fmt.Printf(string(current.char))
					current = &root
				}
			case word:
				if current == nil || current.char == 0 {
					current = &root
				} else {
					fmt.Printf(string(current.char))
					fmt.Printf(string(' '))
					current = &root
				}
			default:
				continue
		}
		if current == nil {
			current = &root
		}
	}
	fmt.Println()
}

func readChar(char *rune) {
	reader := bufio.NewReader(os.Stdin)
	readChar, _, err := reader.ReadRune()

	if err != nil {
		fmt.Printf("Problem with input: %s\n", err)
	} else {
		*char = readChar
	}
}

func buildTree(root *Node) {
	*root = Node{dit: nil, dah: nil}
	root.dit = &Node{char: 'E', dit: nil, dah: nil}
	root.dit.dit = &Node{char: 'I', dit: nil, dah: nil}
	root.dit.dit.dit = &Node{char: 'S', dit: nil, dah: nil}
	root.dit.dit.dit.dit = &Node{char: 'H', dit: nil, dah: nil}
	root.dit.dit.dit.dit.dit = &Node{char: '5', dit: nil, dah: nil}
	root.dit.dit.dit.dit.dah = &Node{char: '4', dit: nil, dah: nil}
	root.dit.dit.dit.dah = &Node{char: 'V', dit: nil, dah: nil}
	root.dit.dit.dit.dah.dah = &Node{char: '3', dit: nil, dah: nil}
	root.dit.dit.dah = &Node{char: 'U', dit: nil, dah: nil}
	root.dit.dit.dah.dit = &Node{char: 'F', dit: nil, dah: nil}
	root.dit.dit.dah.dah = &Node{char: 0, dit: nil, dah: nil}
	root.dit.dit.dah.dah.dit = &Node{dit: nil, dah: nil}
	root.dit.dit.dah.dah.dit.dit = &Node{char: '?', dit: nil, dah: nil}
	root.dit.dit.dah.dah.dit.dah = &Node{char: '_', dit: nil, dah: nil}
	root.dit.dit.dah.dah.dah = &Node{char: '2', dit: nil, dah: nil}

	root.dit.dah = &Node{char: 'A', dit: nil, dah: nil}
	root.dit.dah.dit = &Node{char: 'R', dit: nil, dah: nil}
	root.dit.dah.dit.dit = &Node{char: 'L', dit: nil, dah: nil}
	root.dit.dah.dit.dit.dit = &Node{char: '&', dit: nil, dah: nil}
	root.dit.dah.dit.dit.dah = &Node{dit: nil, dah: nil}
	root.dit.dah.dit.dit.dah.dit = &Node{char: '"', dit: nil, dah: nil}
	root.dit.dah.dit.dah = &Node{dit: nil, dah: nil}
	root.dit.dah.dit.dah.dit = &Node{dit: nil, dah: nil}
	root.dit.dah.dit.dah = &Node{dit: nil, dah: nil}
	root.dit.dah.dit.dah.dit = &Node{char: '+', dit: nil, dah: nil}
	root.dit.dah.dit.dah.dit.dah = &Node{char: '.', dit: nil, dah: nil}
	root.dit.dah.dah = &Node{char: 'W', dit: nil, dah: nil}
	root.dit.dah.dah.dit = &Node{char: 'P', dit: nil, dah: nil}
	root.dit.dah.dah.dit.dah = &Node{dit: nil, dah: nil}
	root.dit.dah.dah.dit.dah.dit = &Node{char: '@', dit: nil, dah: nil}
	root.dit.dah.dah.dah = &Node{char: 'J', dit: nil, dah: nil}
	root.dit.dah.dah.dah.dah = &Node{char: '1', dit: nil, dah: nil}

	root.dah = &Node{char: 'T', dit: nil, dah: nil}
	root.dah.dit = &Node{char: 'N', dit: nil, dah: nil}
	root.dah.dit.dit = &Node{char: 'D', dit: nil, dah: nil}
	root.dah.dit.dit.dit = &Node{char: 'B', dit: nil, dah: nil}
	root.dah.dit.dit.dit.dit = &Node{char: '6', dit: nil, dah: nil}
	root.dah.dit.dit.dit.dit.dah = &Node{char: '-', dit: nil, dah: nil}
	root.dah.dit.dit.dit.dah = &Node{char: '=', dit: nil, dah: nil}
	root.dah.dit.dit.dah = &Node{char: 'X', dit: nil, dah: nil}
	root.dah.dit.dit.dah.dit = &Node{char: '/', dit: nil, dah: nil}
	root.dah.dit.dah = &Node{char: 'K', dit: nil, dah: nil}
	root.dah.dit.dah.dit = &Node{char: 'C', dit: nil, dah: nil}
	root.dah.dit.dah.dit.dah = &Node{dit: nil, dah: nil}
	root.dah.dit.dah.dit.dah.dit = &Node{char: ';', dit: nil, dah: nil}
	root.dah.dit.dah.dit.dah.dah = &Node{char: '!', dit: nil, dah: nil}
	root.dah.dit.dah.dah = &Node{char: 'Y', dit: nil, dah: nil}
	root.dah.dit.dah.dah.dit = &Node{char: '(', dit: nil, dah: nil}
	root.dah.dit.dah.dah.dit.dah = &Node{char: ')', dit: nil, dah: nil}

	root.dah.dah = &Node{char: 'M', dit: nil, dah: nil}
	root.dah.dah.dit = &Node{char: 'G', dit: nil, dah: nil}
	root.dah.dah.dit.dit = &Node{char: 'Z', dit: nil, dah: nil}
	root.dah.dah.dit.dit.dit = &Node{char: '7', dit: nil, dah: nil}
	root.dah.dah.dit.dit.dah = &Node{dit: nil, dah: nil}
	root.dah.dah.dit.dit.dah.dah = &Node{char: ',', dit: nil, dah: nil}
	root.dah.dah.dit.dah = &Node{char: 'Q', dit: nil, dah: nil}
	root.dah.dah.dah = &Node{char: 'O', dit: nil, dah: nil}
	root.dah.dah.dah.dit = &Node{dit: nil, dah: nil}
	root.dah.dah.dah.dit.dit = &Node{char: '8', dit: nil, dah: nil}
	root.dah.dah.dah.dit.dit.dit = &Node{char: ':', dit: nil, dah: nil}
	root.dah.dah.dah.dah = &Node{dit: nil, dah: nil}
	root.dah.dah.dah.dah.dit = &Node{char: '9', dit: nil, dah: nil}
	root.dah.dah.dah.dah.dah = &Node{char: '0', dit: nil, dah: nil}
}