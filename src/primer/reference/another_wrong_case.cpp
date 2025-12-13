#include <string>
#include <vector>

struct Node {
  std::string name;
  std::vector<uint32_t> children;  // indices to other node
};

std::vector<Node> nodes;

void BuildTree() {
  nodes.push_back({"root"});

  Node& root = nodes[0];

  nodes.push_back({"child_1"});
  root.children.push_back(1);

  nodes.push_back({"child_2"});
  root.children.push_back(2);
}

// Fix 1: Don't be lazy ---> use `nodes[0]` replace `root`

// Fix 2: add `nodes.reserve(3);`

// Fix 3: use `GetRootNode()` replace `root`
Node& GetRootNode() {
  return nodes[0];
}
