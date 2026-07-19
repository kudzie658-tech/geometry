class Expression
{
    Point m_p1;
    Point m_p2;

protected:
    void set_p1(const Point& p1){ p1 = p1; }
    void set_p2(const Point& p2){ p2 = p2; }

    Point& get_p1(){ return p1; }
    Point& get_p2(){ return p2; }
    virtual std::string& expression();

public:
    Expression(const Point& p1, const Point& p2): m_p1{p1}, m_p2{p2} {}

    void Print() const
    {
        std::println("Expression: {}", expression());
    }
};

