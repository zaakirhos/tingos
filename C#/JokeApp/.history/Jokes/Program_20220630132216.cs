﻿using System;
using JokesLib;


namespace Jokes
{
    class Program
    {
        static void Main(string[] args)
        {
            Joke horse = new Joke
            {
                Question = "A horse goes into a bar and the bartender says why the long face?",
                Answer = "The horse says, that's racist!"
            };

            Console.WriteLine(horse.Question);
            Console.WriteLine(horse.Answer);
        }
    }
}
