mod test;
mod basics;
pub use basics::*; // put specific name instead of '*' to use all functions

fn main() {
    test::hello();
    primitives::primitive();
    primitives::f();
    tuples::tuple();
}
