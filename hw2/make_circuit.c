/* make_circuit.c
 * This file contains code to make an OR gate out of transistors.
 * Your assignment is to replace it with code that makes a full adder 
 * out of transistors.
 * 
 * Members: Brennan Rouhana, Nebiyou Ersabo, Nick Knighton, Nitesh Duraivel, Zac Zeigler.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "transistors.h"

// input_a, input_b, and output are wires
// make a NOR gate with input wires for a and b and an output wire for a NOR b
// the NOR has the same structure as the one in the lecture notes

void make_nor (circuit *c, int input_a_wire, int input_b_wire, int output_wire) {
	// Get a one node.
	int one = new_node (c, ONE);

	// Get a zero node.
	int zero = new_node (c, ZERO);

	// Get two P and N transistors.
	int p1 = new_node (c, P);
	int p2 = new_node (c, P);
	int n1 = new_node (c, N);
	int n2 = new_node (c, N);

	// wire 0: links zero to the sources of N1 and N2.
	int wire0 = new_wire (c);
	attach_node_to_wire (c, zero, wire0, OUTPUT);
	attach_node_to_wire (c, n1, wire0, INPUT);
	attach_node_to_wire (c, n2, wire0, INPUT);

	// Link input a to the gates of P1 and N2.
	attach_node_to_wire (c, p1, input_a_wire, CONTROL);
	attach_node_to_wire (c, n2, input_a_wire, CONTROL);

	// Link input b to the gates of P2 and N1.
	attach_node_to_wire (c, p2, input_b_wire, CONTROL);
	attach_node_to_wire (c, n1, input_b_wire, CONTROL);

	// Links drains of P2, N2, and N1 to output.
	attach_node_to_wire (c, p2, output_wire, OUTPUT);
	attach_node_to_wire (c, n1, output_wire, OUTPUT);
	attach_node_to_wire (c, n2, output_wire, OUTPUT);

	// wire 4: links output of one to input of P1.
	int wire4 = new_wire (c);
	attach_node_to_wire (c, one, wire4, OUTPUT);
	attach_node_to_wire (c, p1, wire4, INPUT);

	// wire 5: link output of P1 to input of P2.
	int wire5 = new_wire (c);
	attach_node_to_wire (c, p1, wire5, OUTPUT);
	attach_node_to_wire (c, p2, wire5, INPUT);
}

void make_nand(circuit *c, int input_a_wire, int input_b_wire, int output_wire){

    // Get a one node.
    int one = new_node (c, ONE);

    // Get a zero node.
    int zero = new_node (c, ZERO);

    // Get two P and N transistors.
    int p1 = new_node (c, P);
    int p2 = new_node (c, P);
    int n1 = new_node (c, N);
    int n2 = new_node (c, N);

    // wire 0: 
    int wire0 = new_wire (c);
    attach_node_to_wire (c, one, wire0, OUTPUT);
    attach_node_to_wire (c, p1, wire0, INPUT);
    attach_node_to_wire (c, p2, wire0, INPUT);

    // Link input a to the gates of N1 and P2.
    attach_node_to_wire (c, n1, input_a_wire, CONTROL);
    attach_node_to_wire (c, p2, input_a_wire, CONTROL);

    // Link input b to the gates of N2 and P1.

    attach_node_to_wire (c, n2, input_b_wire, CONTROL);
    attach_node_to_wire (c, p1, input_b_wire, CONTROL);

    // Links drains of N2, P1, and P2 to output.
    attach_node_to_wire (c, n2, output_wire, OUTPUT);
    attach_node_to_wire (c, p1, output_wire, OUTPUT);
    attach_node_to_wire (c, p2, output_wire, OUTPUT);

    // wire 4: links output of zero to input of N1.
    int wire4 = new_wire (c);
    attach_node_to_wire (c, zero, wire4, OUTPUT);
    attach_node_to_wire (c, n1, wire4, INPUT);

    // wire 5: link output of N1 to input of N2.
    int wire5 = new_wire (c);
    attach_node_to_wire (c, n1, wire5, OUTPUT);
    attach_node_to_wire (c, n2, wire5, INPUT);

}

// Make an inverter that puts the NOT of the signal from the input wire
// onto the output wire.
void make_inverter (circuit *c, int input_wire, int output_wire) {
	int	p, n, one, zero, wire0, wire1;

	// Get P and N transistors.
	p = new_node (c, P);
	n = new_node (c, N);

	// Get a one and a zero.
	one = new_node (c, ONE);
	zero = new_node (c, ZERO);

	// Make a couple of wires.
	wire0 = new_wire (c);
	wire1 = new_wire (c);

	// Connect input wire to gates of p and n.
	attach_node_to_wire (c, p, input_wire, CONTROL);
	attach_node_to_wire (c, n, input_wire, CONTROL);

	// Attach zero to source of N.
	attach_node_to_wire (c, zero, wire0, OUTPUT);
	attach_node_to_wire (c, n, wire0, INPUT);

	// Attach one to source of P.
	attach_node_to_wire (c, one, wire1, OUTPUT);
	attach_node_to_wire (c, p, wire1, INPUT);

	// Attach drain of P and N to output.
	attach_node_to_wire (c, p, output_wire, OUTPUT);
	attach_node_to_wire (c, n, output_wire, OUTPUT);
}

// Make an OR gate that takes input wires a and b and puts a OR b on the output wire.
// We'll do this the easy way: wire up the NOR of a and b to an inverter.
void make_or (circuit *c, int input_wire_a, int input_wire_b, int output_wire) {

	// Get a wire.
	int connect_wire = new_wire (c);

	// Get the NOR of the inputs onto that wire.
	make_nor (c, input_wire_a, input_wire_b, connect_wire);

	// Hook up the output of the NOR to the input of the inverter, 
	// and put the output of the inverter on our output.
	make_inverter (c, connect_wire, output_wire);
}

// This makes the whole circuit with inputs and output.
void make_circuit (circuit *c) {
	// Three input nodes for the circuit.

	int input_a = new_node (c, INPUT_NODE);
	int input_b = new_node (c, INPUT_NODE);
	int input_c = new_node (c, INPUT_NODE);

	// Three wires to connect to the inputs.
 
	int input_wire_a = new_wire (c);
	int input_wire_b = new_wire (c);
	int input_wire_c = new_wire (c);

	attach_node_to_wire (c, input_a, input_wire_a, OUTPUT);
	attach_node_to_wire (c, input_b, input_wire_b, OUTPUT);
	attach_node_to_wire (c, input_c, input_wire_c, OUTPUT);

	// One output node for the circuit.

	int output_1 = new_node (c, OUTPUT_NODE);
	int output_2 = new_node (c, OUTPUT_NODE);

	// One wire for the output.

	int output_wire_1 = new_wire (c);
	int output_wire_2 = new_wire (c);

	attach_node_to_wire (c, output_1, output_wire_1, INPUT);
	attach_node_to_wire (c, output_2, output_wire_2, INPUT);

	//Wire Declarations
	int nand_wire_1 = new_wire(c);
	int nand_wire_2 = new_wire(c);
	int nand_wire_3 = new_wire(c);
	int nand_wire_4 = new_wire(c);
	int nand_wire_5 = new_wire(c);
	int nand_wire_6 = new_wire(c);
	int nand_wire_7 = new_wire(c);

	//Node operations
	make_nand(c, input_wire_a, input_wire_b, nand_wire_1);
	make_nand(c, input_wire_a, nand_wire_1, nand_wire_2);
	make_nand(c, input_wire_b, nand_wire_1, nand_wire_3);
	make_nand(c, nand_wire_2, nand_wire_3, nand_wire_4);
	make_nand(c, input_wire_c, nand_wire_4, nand_wire_5);
	make_nand(c, nand_wire_4, nand_wire_5, nand_wire_6);
	make_nand(c, nand_wire_5, input_wire_c, nand_wire_7);

	//PARITY
	make_nand(c, nand_wire_6, nand_wire_7, output_wire_1);

	//MAJORITY
	make_nand(c, nand_wire_1, nand_wire_5, output_wire_2);
}
