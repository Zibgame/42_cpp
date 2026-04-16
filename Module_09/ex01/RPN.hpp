/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcadinot <zcadinot@student.42lehavre.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:47:09 by zcadinot          #+#    #+#             */
/*   Updated: 2026/04/16 17:47:14 by zcadinot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN
{
public:
    RPN();
    ~RPN();

    int evaluate(const std::string& expression);

private:
    std::stack<int> _stack;

    bool isOperator(const std::string& token) const;
    int applyOperation(int a, int b, const std::string& op);
};

#endif
