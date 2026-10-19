# nd-candidates-test

Tiny fixture for COR-4039: a value-keyed std::unordered_map iterated with the
range-for forms the 3.3 pattern widened to catch (structured binding, auto
const&, pointer declarator), plus the plain form it already caught before the
fix, as a regression check.
