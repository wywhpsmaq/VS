#include <bits/stdc++.h>
using namespace std;

pair<string, string> divide(string dividend, string divisor) {
    if (divisor == "0")
        throw invalid_argument("Divisor cannot be zero.");
        
    // 处理符号
    bool isNegativeDividend = dividend[0] == '-';
    bool isNegativeDivisor = divisor[0] == '-';
    bool isNegativeQuotient = isNegativeDividend != isNegativeDivisor;
    
    // 去除符号后的绝对值
    if (isNegativeDividend)
        dividend = dividend.substr(1);

    if (divisor == "0")
        throw invalid_argument("Divisor cannot be zero.");

    string quotient = "";
    string remainder = "";

    for (char digit : dividend)
    {
        remainder += digit;
        int num = stoi(remainder);
        quotient += (num / stoi(divisor)) + '0';
        remainder = to_string(num % stoi(divisor));
    }

    // Remove leading zeros from quotient
    quotient.erase(0, quotient.find_first_not_of('0'));
    if (quotient.empty())
        quotient = "0";

    // Remove leading zeros from remainder
    remainder.erase(0, remainder.find_first_not_of('0'));
    if (remainder.empty())
        remainder = "0";

    return {quotient, remainder};
}

int main()
{
    string dividend, divisor;
    cin >> dividend;
    cin >> divisor;

    try
    {
        pair<string, string> result = divide(dividend, divisor);
        cout << result.first << endl;
        cout << result.second << endl;
    }
    catch (const invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}