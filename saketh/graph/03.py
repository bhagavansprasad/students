import networkx as nx
import matplotlib.pyplot as plt

# Create an empty graph
graph = nx.Graph()

# Add nodes
graph.add_node("A")
graph.add_node("B")
graph.add_node("C")
graph.add_node("D")
graph.add_node("E")
graph.add_node("F")

# Add edges
graph.add_edge("A", "B")
graph.add_edge("A", "C")
graph.add_edge("B", "C")
graph.add_edge("B", "D")
graph.add_edge("C", "D")
graph.add_edge("C", "E")
graph.add_edge("D", "E")
graph.add_edge("D", "F")
graph.add_edge("E", "F")

# Draw the graph
pos = nx.spring_layout(graph)
nx.draw_networkx(graph, pos, with_labels=True, node_color="lightblue", edge_color="gray")
plt.title("Graph")
plt.axis("off")
plt.show()

