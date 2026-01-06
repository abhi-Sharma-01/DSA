/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let currentval = init;
    return{
        increment: function(){
            currentval++;
            return currentval;
        },
        decrement: function(){
            currentval --;
            return currentval;
        },
        reset: function(){
            currentval = init;
            return currentval;
        }

    }    
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */