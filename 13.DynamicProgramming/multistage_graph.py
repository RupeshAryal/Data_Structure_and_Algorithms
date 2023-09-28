#data structure:

adjacency_list = {
    1: [(2, 2), (3, 3)],
    2: [(4, 1), (5, 2)],
    3: [(4, 3), (5, 1), (6, 2), (7, 4)],
    4: [(8, 3), (9, 2), (10, 1)],
    5: [(8, 2), (9, 1)],
    6: [(10, 3)],
    7: [(8, 2), (10, 4)],
    8: [(14, 1), (11,2), (13,4)],
    9: [(14, 3), (12, 2)],
    10: [(11,3), (13,2)],
    11: [(15,5)],
    12: [(15,3)],
    13: [(15,2)],
    14: [(15,1)],
    15: [(15,0)]
}

levels = {
    'l6': [15],  # Only one element (the destination vertex)
    'l5': [11,12,13,14],
    'l4': [8, 9, 10],
    'l3': [4, 5, 6, 7],
    'l2': [2, 3],
    'l1': [1]
}


vdc = {levels['l6'][0]: (0, levels['l6'][0])} # vertex: {min_cost, next_node}



def multistage_graph(adjaceny_list, levels, vdc):
    for level in levels:
        for vertices in levels[level]:
            next_node, cost = get_cost(vertices, adjacency_list, vdc)
            vdc[vertices] = (next_node,cost)

    
    minimum_cost = vdc[levels['l1'][0]][0]

    return minimum_cost, vdc



def get_cost(vertex, adjacency_list, vdc):
    get_all_cost = []
    for neighbor in adjacency_list[vertex]:
        next_node = neighbor[0]
        cost_toreach_nn = neighbor[1]
        x = (cost_toreach_nn + vdc[next_node][0], next_node)
        get_all_cost.append(x)

    return min(get_all_cost, key=lambda x: x[0])




def display_path(cost_list):
    display_msg = ''
    final_vertex, first_vertex = list(cost_list.keys())[0], list(cost_list.keys())[-1]

    current_vertex = first_vertex
    while current_vertex != final_vertex:
        display_msg += f'{current_vertex} ---- > '
        current_vertex = cost_list[current_vertex][1]

    display_msg += f"{current_vertex}"

    print(display_msg)



minimum_cost, cost_list = multistage_graph(adjacency_list, levels, vdc)
print(f'minimum cost to reach from first to final is {minimum_cost}')
print(cost_list)
display_path(cost_list)


