#include <vector>

template <typename T>
std::vector<T> MergeSort(const std::vector<T>& a)
{
	std::vector<T> r = a;	

	//Base Case. A list of 1 or 0 are automatically Sorted. 
	if(r.length() <= 1)
		return r;

	//Splits recursvily To the Left and right portions of the list.
	std::vector<T> left;
	std::vector<T> right;

	//Divide the total List into equal Sized Sublists.
	for(int i = 0; i < r.length(); i++)
	{
		if(i <= r.length()/2 )
		{r[i] = left[i];}
		else
		{r[i] = right[i];}
	}

	//Sort both Sublists using the same method.
	left = mergeSort(left);
	right = mergeSort(right);

	//Return the merge of left and right.
	//Defined next slide. 
	return merge(left, right);
}



template <typename T>
std::vector<T> merge(std::vector<T> left, std::vector<T> right)
{
	std::vector<T> result;

	//Adds Sorted elements to return array, and removes old elements from Vector
	while(!left.empty() && !right.empty())
		if(left[0] <= right[0])
		{
			result[0] = left[0];
			left.erase(0);
 		}
 		else
 		{
 			result[0] = right[0];
 			right.erase(0);
 		}

 	//Exeption Condition for leftover values in either array.
 	/
 	while(!left.empty())
 	{
 		result[0] = left[0];
 		left.erase[0];
 	}
 	while(!right.empty())
 	{
 		result[0] = right[0];
 		right.erase(0);
 	}
 	return result;
}