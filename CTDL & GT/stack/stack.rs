/*
    Stack Rust
*/

use std::time::SystemTime;

struct Stack<T> {
    arr: Vec<T>,
    length: usize,
    capacity: usize,
}

impl<T> Stack<T> {
    fn new() -> Self {
        Stack {
            arr: Vec::with_capacity(10),
            length: 0,
            capacity: 10,
        }
    }

    fn resize(&mut self) {
        self.capacity *= 2;
        self.arr.reserve(self.capacity - self.arr.len());
    }

    fn push(&mut self, value: T) {
        if self.length == self.capacity {
            self.resize();
        }
        self.arr.push(value);
        self.length += 1;
    }

    fn pop(&mut self) -> Option<T> {
        if self.length == 0 {
            println!("Stack is empty");
            None
        } else {
            self.length -= 1;
            self.arr.pop()
        }
    }

    fn top(&self) -> Option<&T> {
        if self.length == 0 {
            println!("Stack is empty");
            None
        } else {
            self.arr.get(self.length - 1)
        }
    }

    fn is_empty(&self) -> bool {
        self.length == 0
    }
}

fn main() {
    let mut s = Stack::new();
    let mut rng = rand::thread_rng();
    for _ in 1..=10 {
        s.push(rand::random::<u32>() % 100 + 1);
    }

    println!("{}", if s.is_empty() { "Is empty" } else { "Is available" });
    for i in 0..s.length {
        println!("{}", s.arr[i]);
    }

    s.pop();
    if let Some(top) = s.top() {
        println!("\nTop element after pop: {}", top);
    }

    println!("\nlength: {}", s.length);
    println!("\ncapacity: {}", s.capacity);
}
