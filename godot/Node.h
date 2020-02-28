//
// Created by Adam on 2/27/2020.
//

#ifndef REACTORCPPTEST_NODE_H
#define REACTORCPPTEST_NODE_H

class Node
{
public:
	virtual ~Node();
	virtual void _physics_process(float delta) = 0;
};

#endif //REACTORCPPTEST_NODE_H
