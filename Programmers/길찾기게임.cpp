#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
	int idx, x, y;
	Node* left;
	Node* right;
};

// 내림차순
bool compare(Node a, Node b) {
	// y좌표가 같으면, x 좌표가 
	if (a.y == b.y) {
		return a.x < b.x;
	}
	return a.y > b.y;
}

void addNode(Node *parent, Node *child) {
	if (child->x < parent->x) {
		if (parent->left == NULL) {
			parent->left = child;
		}
		else {
			addNode(parent->left, child);
		}
	}
	else {
		if (parent->right == NULL) {
			parent->right = child;
		}
		else {
			addNode(parent->right, child);
		}
	}
}

// 전위 순회
void preorder(vector<int> &answer, Node *node) {
	if (node == NULL) return;

	answer.push_back(node->idx);
	preorder(answer, node->left);
	preorder(answer, node->right);
}

// 후위 순회
void postorder(vector<int> &answer, Node *node) {
	if (node == NULL) return;

	postorder(answer, node->left);
	postorder(answer, node->right);
	answer.push_back(node->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<vector<int>> answer = { {}, {} };
	vector<Node> nodes;

	for (int i = 0; i < nodeinfo.size(); i++) {
		// {idx, x, y}
		// idx가 노드 번호
		nodes.push_back({ i + 1, nodeinfo[i][0], nodeinfo[i][1] });
	}

	// 노드를 y의 내림차순으로 정렬
	sort(nodes.begin(), nodes.end(), compare);

	Node *root = &nodes[0];

	// 트리 구성
	for (int i = 1; i < nodes.size(); i++) {
		addNode(root, &nodes[i]);
	}

	// 전순위 운행
	preorder(answer[0], root);

	// 후순위 운행
	postorder(answer[1], root);

	return answer;
}
