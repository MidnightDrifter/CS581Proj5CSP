#include "csp.h"
#ifdef INLINE_CSP
	//#warning "INFO - inlining CSP methods"
	#define INLINE inline
#else   
	//#warning "INFO - NOT inlining CSP methods"
	#define INLINE 
#endif

////////////////////////////////////////////////////////////
//CSP constructor
template <typename T> 
CSP<T>::CSP(T &cg) :
	arc_consistency(),
	cg(cg),
	solution_counter(0),
	recursive_call_counter(0),
	iteration_counter(0) 
{
}

////////////////////////////////////////////////////////////
//CSP solver, brute force - no forward checking
template <typename T> 
bool CSP<T>::SolveDFS(unsigned level) {
	++recursive_call_counter;
	//std::cout << "entering SolveDFS (level " << level << ")\n";





    //choose a variable by MRV
	Variable* var_to_assign = MinRemVal();
	//Variable* var_to_assign = MaxDegreeHeuristic();





    loop( ... ) {
        ++iteration_counter;



    }



}


////////////////////////////////////////////////////////////
//CSP solver, uses forward checking
template <typename T> 
bool CSP<T>::SolveFC(unsigned level) {
	++recursive_call_counter;
	//std::cout << "entering SolveFC (level " << level << ")\n";

	
    
    //choose a variable by MRV
	Variable* var_to_assign = MinRemVal();
	//Variable* var_to_assign = MaxDegreeHeuristic();

	

    loop( ... ) {
        ++iteration_counter;



    }



}
////////////////////////////////////////////////////////////
//CSP solver, uses arc consistency
template <typename T> 
bool CSP<T>::SolveARC(unsigned level) {
	++recursive_call_counter;
	//std::cout << "entering SolveARC (level " << level << ")\n";

	
    
    
    
    //choose a variable by MRV
	Variable* var_to_assign = MinRemVal();

    
    
	
    
    loop( ... ) {
        ++iteration_counter;



    }



}


template <typename T> 
INLINE
bool CSP<T>::ForwardChecking(Variable *x) {




}
////////////////////////////////////////////////////////////
//load states (available values) of all unassigned variables 
template <typename T> 
void CSP<T>::LoadState(
		std::map<Variable*, 
		std::set<typename CSP<T>::Variable::Value> >& saved) const 
{
	typename std::map<Variable*, std::set<typename Variable::Value> >::iterator 
		b_result = saved.begin();
	typename std::map<Variable*, std::set<typename Variable::Value> >::iterator 
		e_result = saved.end();

	for ( ; b_result != e_result; ++b_result ) {
		//std::cout << "loading state for " 
		//<< b_result->first->Name() << std::endl;
		(*b_result).first->SetDomain( (*b_result).second );
	}
}


////////////////////////////////////////////////////////////
//save states (available values) of all unassigned variables 
//except the current
template <typename T> 
INLINE
std::map< typename CSP<T>::Variable*, std::set<typename CSP<T>::Variable::Value> > 
CSP<T>::SaveState(typename CSP<T>::Variable* x) const {
	std::map<Variable*, std::set<typename Variable::Value> > result;

	const std::vector<Variable*>& all_vars = cg.GetAllVariables();
	typename std::vector<Variable*>::const_iterator 
		b_all_vars = all_vars.begin();
	typename std::vector<Variable*>::const_iterator 
		e_all_vars = all_vars.end();
	for ( ; b_all_vars!=e_all_vars; ++b_all_vars) {
		if ( !(*b_all_vars)->IsAssigned() && *b_all_vars!=x ) {
			//std::cout << "saving state for " 
			//<< (*b_all_vars)->Name() << std::endl;
			result[ *b_all_vars ] = (*b_all_vars)->GetDomain();
		}
	}
	return result;
}
////////////////////////////////////////////////////////////
//check the current (incomplete) assignment for satisfiability
template <typename T> 
INLINE
bool CSP<T>::AssignmentIsConsistent( Variable* p_var ) const {




	for (auto constraintIter = cg.GetConstraints(p_var).begin(); constraintIter != cg.GetConstraints(p_var).end(); constraintIter++)
	{
		Constraint* temp = (*constraintIter)->clone();
		temp->AddVariable(p_var);
		if (!temp->Satisfiable())
		{
			delete temp;  //Check if this deletes all the variables inside it!!
			return false;
		}

		delete temp;   //Check if this deletes all the variables inside it!!
	}


	return true;


}
////////////////////////////////////////////////////////////
//insert pair 
//(neighbors of the current variable, the current variable)
//current variable is the variable that just lost some values
// for all y~x insert (y,x)
//into arc-consistency queue
template <typename T> 
INLINE
void CSP<T>::InsertAllArcsTo( Variable* cv ) {











}
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
//AIMA p.146 AC-3 algorithm
template <typename T> 
INLINE
bool CSP<T>::CheckArcConsistency(Variable* x) {












}
////////////////////////////////////////////////////////////
//CHECK that for each value of x there is a value of y 
//which makes all constraints involving x and y satisfiable


//Do I actually go through and remove the values that are inconsistent, or just check for them here??

template <typename T> 
INLINE
bool CSP<T>::RemoveInconsistentValues(Variable* x,Variable* y,const Constraint* c) {


	bool out = false;

	Constraint* temp = c->clone();
	temp->AddVariable(x);
	temp->AddVariable(y);   //Check if the Constraint destructor deletes the variables inside it!

	if (temp)
	{
		out = temp->Satisfiable();
		delete temp;   //Check if this deletes vars inside it!
	}

	return out;










}
////////////////////////////////////////////////////////////
//choose next variable for assignment
//choose the one with minimum remaining values
template <typename T> 
INLINE
typename CSP<T>::Variable* CSP<T>::MinRemVal() {




	auto i = cg.GetAllVariables.begin();

	CSP<T>::Variable* out = *i;   //If there are no variables, something will go wrong here most likely

	for ( ; i != cg.GetAllVariables().end(); i++)
	{
		
		if (out->SizeDomain() > (*i)->SizeDomain())
		{
			out = *i;
		}
		

	}

	return out;





}
////////////////////////////////////////////////////////////
//choose next variable for assignment
//choose the one with max degree
template <typename T> 
typename CSP<T>::Variable* CSP<T>::MaxDegreeHeuristic() {






	//Choose variable that touches the MOST constraints
	//Vars don't know about constraints, but constraints know about vars

	//Variable* out = nullptr;


	std::pair<Variable*, int> temp(nullptr, 0);

	for (auto varIter = cg.GetAllVariables.begin(); varIter != cg.GetAllVariables.end(); varIter++)
	{
		if (cg.GetConstraints(*varIter).size() > temp.second)
		{
			temp.first = *varIter;
			temp.second = cg.GetConstraints(*varIter);
		}
	}


	return pair.first;





}
#undef INLINE
