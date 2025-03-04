
namespace config {
    typedef struct {
        bool if_equal;
        bool if_zero;
        bool if_not_equal;
        bool if_not_zero;
        bool if_greater;
        bool if_not_less_or_equal;
        bool if_greater_or_equal;
        bool if_not_less;
        bool if_less;
        bool if_not_greater_or_equal;
        bool if_less_or_equal;
        bool if_not_greater;
    } statusFlag_t;

    class conf {
    public:
        void init();
        void print();

        statusFlag_t cFlags;
    };
    extern conf Conf;
}