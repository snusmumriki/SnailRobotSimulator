#include "robot.h"

void update() {

	Node *node_list = calloc(sizeof(Node), nodes_num);
	for (int i = 0; i < nodes_num; i++)
		node_list[i].drive = malloc(sizeof(Drive) * adj_nums[i]);
	
	for (int i = 0; i < rows_num; i++)
		free(num_sheme[i]);
	free(num_sheme);
	free(adj_nums);

	float *drive_state_list = malloc(sizeof(float) * drives_num);
	for (int i = 0; i < drives_num; i++) {
		drive_state_list[i] = DRIVE_INIT_STATE;
		Node *node0 = node_list + edge_list[i].node0;
		Node *node1 = node_list + edge_list[i].node1;
		
		node0->drive[node0->drives_num].node = node1;
		node0->drives_num++; 
		node1->drive[node1->drives_num].node = node0;
		node1->drives_num++; 
	}
	Robot *robot = malloc(sizeof(Robot));
	robot->nodes_num = nodes_num;
	robot->node_list = node_list;
	robot->drives_num = drives_num;
	robot->drive_state_list = drive_state_list;
	
	return robot;
}
