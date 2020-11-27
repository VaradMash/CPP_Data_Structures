/*
 * Converter.h
 *
 *  Author: Varad Mashalkar
 *  Lab : Data Structures and Algorithms
 *  Assignment : 2
 *  File Description : This file contains the Converter ADT
 */

#include "ADT.h"
#include <cmath>

#ifndef SRC_CONVERTER_H_
#define SRC_CONVERTER_H_

class converter
{
private:
	char expression[80], prefix[80], postfix[80];
public:
	int precedence(char);			//Method to return the precedence of operators
	bool isoperator(char);			//method to check if the passed character is an operator
	int assosciativity(char c);		//Method to check Associativity of operator
	void infixToPostfix(bool);		//Method to convert infix expression to postfix
	void infixToPrefix();			//Method to convert infix expression to prefix
	void display(int);				//Display postfix or prefix depending on key
	void getInfix();				//Method to get infix expression from user
	void reverse(int);				//Method to reverse requested expression
	void evaluateUsingPostfix();	//method to evaluate current expression using postfix
	void evaluateUsingPrefix();		//method to evaluate current expression using prefix
	char* getPostfix();				//Getter method for postfix expression.
};

//Method to return the precedence of operators
int converter::precedence(char op)
{
	/*
	 * Input : Character
	 * Utility : Determine precedence of operator.
	 * Output : Integer value corresponding to precedence.
	 */
	int precedence = 0;
	if(op == '^')
	{
		precedence = 3;
	}
	else if (op == '%' || op == '/' || op == '*')
	{
		precedence = 2;
	}
	else if (op == '+' || op == '-')
	{
		precedence = 1;
	}
	return precedence;
}

//method to check if the passed character is an operator
bool converter::isoperator(char c)
{
	/*
	 * Input : Character
	 * Utility : Determine whether character is an operator.
	 * Output : Boolean true or false value.
	 */
	if(c=='+' || c=='-' || c=='*' || c=='/'||c=='^' || c=='%')
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Method to check Associativity of operator
int converter::assosciativity(char op)
{
	/*
	 * Input : Character
	 * Utility : Determine associativity of operator.
	 * Output : Integer value corresponding to associativity.
	 */
	//Right to left
	if (op == '^')
	{
		return 1;
	}
	//Left to right
	else
	{
		return 2;
	}
}

//Method to convert infix expression to postfix
void converter::infixToPostfix(bool forPostfix)
{
	/*
	 * Input : Infix expression.
	 * Utility : Convert infix expression to postfix form.
	 * Output : Postfix expression.
	 */
	Stack<char> S;
	int i = 0, j = 0;
	//input expression, postfix, operator stack
	if(forPostfix)
	{
		cout<<"Sr.No.\t|Token\t|Operator Stack\t\tPostfix"<<endl;
	}
	else
	{
		cout<<"Sr.No.\t|Token\t|Operator Stack\t\tPrefix"<<endl;
	}
	while(expression[i]!='\0')
	{
		char token = expression[i];
		//If alphanumeric character is present, append to postfix array
		if(isalnum(token))
		{
			postfix[j++] = token;
		}
		//If opening bracket is found, push to stack
		if(token == '(')
		{
			S.push(token);
		}
		//If closing bracket is found, pop till an opening bracket is found
		if(token == ')')
		{
			char out = S.pop();
			while(out != '(' && !S.isEmpty())
			{
				postfix[j++] = out;
				out = S.pop();
			}
		}
		//If token is a character, execute the following block
		if(isoperator(token))
		{
			//If stack is empty, push operator to stack
			if(S.isEmpty())
			{
				S.push(token);
			}
			//else evaluate precedences
			else
			{
				//append operators to postfix array if precedence of token is less than that of top of stack
				while((this->precedence(S.peep()) > this->precedence(token)) && !S.isEmpty())
				{
					postfix[j++] = S.pop();
				}
				//for equal precedences, execute following block
				if(precedence(token) == precedence(S.peep()))
				{
					//right to left associativity
					if(assosciativity(token) == 1)
					{
						S.push(token);
					}
					//left to right associativity
					if(assosciativity(token) == 2)
					{
						postfix[j++] = S.pop();
						S.push(token);
					}
				}
				else
				{
					S.push(token);
				}
			}
		}
		postfix[i+1] = '\0';
		//cout<<"Sr.No.\t|Token\t|Operator Stack\t\t|Prefix"<<endl;
		if (!forPostfix)
		{
			this->reverse(3);
		}
		cout<<(i+1)<<"\t|"<<token<<"\t|";
		S.displayStack();
		cout<<"\t\t|"<<postfix<<endl;
		if (!forPostfix)
		{
			this->reverse(3);
		}
		i++;
	}
	//pop all remaining elements of stack and append to postfix
	while(!S.isEmpty())
	{
		postfix[j++] = S.pop();
		cout<<(i+1)<<"\t|"<<"-"<<"\t|";
		S.displayStack();
		cout<<"\t\t|"<<postfix<<endl;
		i +=1 ;
	}
	//terminate postfix string
	postfix[j] = '\0';
	if(forPostfix)
	{
		this->display(0);
	}
}

//Display postfix or prefix depending on key
void converter::display(int key)
{
	/*
	 * Input : key
	 * Utility : Display postfix or prefix form depending on the key.
	 * Output : Pre/PostFix Expression.
	 */
	//Postfix expression.
	if(key == 0)
	{
		cout<<"\nPostfix Expression : "<<endl;
		cout<<postfix<<endl;
	}
	//Prefix expression.
	if(key == 1)
	{
		cout<<"\nPrefix Expression : "<<endl;
		cout<<prefix<<endl;
	}
}

//Method to get infix expression from user
void converter::getInfix()
{
	/*
	 * Input : None
	 * Utility : Get and validate infix expression.
	 * Output : None
	 */
	bool isValid = false;
	cout<<"\nEnter Infix Expression : "<<endl;
	while(!isValid)
	{
		cin.getline(expression, 80);
		/*
		 * Number of Opening and closing brackets should be of same in number
		 * expression should not start with operator
		 * number of operators should be 1 less than number of operands
		 * expression should not end with operator
		 * expression should not have consecutive operators
		 *  */
		int i = 0, bracketOpen = 0, bracketClose = 0, operators = 0;
		while(expression[i] != '\0')
		{
			if (expression[i] == '(')
				bracketOpen += 1;
			if (expression[i] == ')')
				bracketClose += 1;
			if (this->isoperator(expression[i]))
				operators += 1;
			if (this->isoperator(expression[i]) && expression[i+1] == '\0')
				break;
			if (this->isoperator(expression[i]) && this->isoperator(expression[i+1]) && expression[i+1] != '\0')
				break;
			i += 1;
		}
		/*
		cout<<"Bracket Open : "<<bracketOpen<<endl;
		cout<<"Bracket Close: "<<bracketClose<<endl;
		cout<<"Operators "<<operators<<endl;
		cout<<"bracketOpen == bracketClose "<<(bracketOpen == bracketClose)<<endl;
		cout<<"operators*2 + 1 == (i-bracketOpen - bracketClose) "<<(operators*2 + 1 == (i-bracketOpen - bracketClose))<<endl;
		cout<<"!this->isoperator(expression[0]) "<<(!this->isoperator(expression[0]))<<endl;
		cout<<"value of i : "<<i<<endl;*/

		if(bracketOpen == bracketClose && operators*2 + 1 == (i-bracketOpen - bracketClose) && !this->isoperator(expression[0]))
		{
			isValid = true;
		}
		else
		{
			cout<<"Enter Valid infix expression !"<<endl;
		}
	}
}

//Method to evaluate expression
void converter::evaluateUsingPostfix()
{
	/*
	 * Input : Postfix expression.
	 * Utility : Evaluate postfix expression.
	 * Output : Result.
	 */
	int i = 0;
	//Satck Store to operands
	Stack<float> operands;
	this->infixToPostfix(true);
	i = 0;
	cout<<"Sr.No.\t|Token\t\t|Result\t|Operand Stack"<<endl;
	while(postfix[i] != '\0')
	{
		char token = postfix[i];
		if(isalpha(token))
		{
			float temp;
			cout<<"Enter Value of "<<token<<endl;
			cin>>temp;
			operands.push(temp);
		}
		if(isdigit(token))
		{
			operands.push((int)token - 48);
		}
		if(this->isoperator(token) && !operands.isEmpty())
		{
			float op2 = operands.pop();
			float op1 = operands.pop();
			if(token == '+')
			{
				operands.push(op1 + op2);
			}
			else if(token == '-')
			{
				operands.push(op1 - op2);
			}
			else if(token == '*')
			{
				operands.push(op1*op2);
			}
			else if(token == '/')
			{
				operands.push(op1/op2);
			}
			else if(token == '%')
			{
				operands.push((int)op1%(int)op2);
			}
			else if(token == '^')
			{
				operands.push(pow(op1, op2));
			}
		}
		i += 1;
		//cout<<"Sr.No.\t|Token\t\t|Result\t|Operand Stack"<<endl;
		cout<<(i)<<"\t|"<<token<<"\t\t|"<<operands.peep()<<"\t|";
		operands.displayStack();
		cout<<endl;
	}
	cout<<"Result : "<<operands.pop()<<endl;
}

void converter::infixToPrefix()
{
	//reversing infix expression
	this->reverse(0);
	this->infixToPostfix(false);
	//reversing postfix. append to prefix
	this->reverse(1);
	//reversing infix for further reuse
	this->reverse(0);
	//display prefix expression
	this->display(1);
}

//Method to reverse requested expression
void converter::reverse(int key)
{
	/*
	 * Reverse method to reverse strings(expressions) based on key value.
	 */
	Stack<char> S;
	//reverse infix store in infix
	if(key == 0)
	{
		int i = 0;
		while(expression[i] != '\0')
		{
			S.push(expression[i]);
			i++;
		}
		i = 0;
		while(!S.isEmpty())
		{
			expression[i++] = S.pop();
		}
		expression[i] = '\0';
	}
	//reverse postfix store in prefix
	if (key == 1)
	{
		int i = 0;
		while(postfix[i] != '\0')
		{
			S.push(postfix[i]);
			i++;
		}
		i = 0;
		while(!S.isEmpty())
		{
			prefix[i++] = S.pop();
		}
		prefix[i] = '\0';
	}
	//reverse prefix store in postfix
	if (key == 2)
	{
		int i = 0;
		while(prefix[i] != '\0')
		{
			S.push(prefix[i]);
			i++;
		}
		i = 0;
		while(!S.isEmpty())
		{
			postfix[i++] = S.pop();
		}
		postfix[i] = '\0';
	}
	if (key == 3)
	{
		int i = 0;
		while(postfix[i] != '\0')
		{
			S.push(postfix[i]);
			i++;
		}
		i = 0;
		while(!S.isEmpty())
		{
			postfix[i++] = S.pop();
		}
		postfix[i] = '\0';
	}
}

void converter::evaluateUsingPrefix()
{
	/*
	 * Method to evaluate prefix expression.
	 */
	this->infixToPrefix();
	this->reverse(2);
	this->evaluateUsingPostfix();
}

char* converter::getPostfix()
{
	/*
	 * Getter method for postfix expression.
	 */
	return (char*)postfix;
}

#endif /* SRC_CONVERTER_H_ */
