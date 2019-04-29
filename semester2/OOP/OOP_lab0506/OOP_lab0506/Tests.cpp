//#include "DynamicVector.h"
//#include "Tutorial.h"
//#include "Repository.h"
//#include "Controller.h"
//#include <exception>
//#include "Tests.h"
//
//#include <sstream>
//
//#include <iostream>
//
//#include <Windows.h>
//#include <vector>
//
//void test_DynamicVector()
//{
//	Duration d1{ 11, 57 };
//	Duration d2{ 40,24 };
//	Duration d3{ 70,30 };
//	Duration d3_new{ 70,32 };
//	Tutorial t1{ "Function Pointers in C/C++","mycodeacademy",d1,2000, "https://www.youtube.com/watch?v=ynYtgGUNelE" };
//	Tutorial t2{ "C++ Tutorial 10 : Object Oriented Programming","Derek Banas",d2, 844,"https://www.youtube.com/watch?v=ZOKLjJF54Xc" };
//	Tutorial t3{ "C++ Programming", "Derek Banas", d3, 49000,"https://www.youtube.com/watch?v=Rub-JsjMhWY" };
//	Tutorial t3_new{ "C++ Programming", "Derek Banas", d3_new, 49000,"https://www.youtube.com/watch?v=Rub-JsjMhWY" };
//
//	DynamicVector<Tutorial> v1{ 2 };
//	assert(v1.get_size() == 0);
//	v1 = t1 + v1;
//	//v1 = v1 + t1;
//	//v1.add(t1);
//	assert(v1.get_size() == 1);
//	DynamicVector<Tutorial> v2{ v1 };
//	DynamicVector<Tutorial> v3{};
//
//	v3 = v3;
//	v3 = v2;
//
//
//	
//	v1 = v1 + t2;
//	assert(v1[1] == t2);
//	assert(v1.get_size() == 2);
//	v1.add(t3);
//	assert(v1.get_size() == 3);
//	try
//	{
//		v1.add(t1);
//		assert(false);
//
//	}
//	catch (std::exception &exc)
//	{
//		//cout << exc.what();
//		assert(true);
//
//	}
//
//	assert(v1.get_size() == 3);
//
//	v1.remove(t1);
//	assert(v1.get_size() == 2);
//
//	try
//	{
//		v1.remove(t1);
//		assert(false);
//	}
//	catch (std::exception &exc)
//	{
//		assert(true);
//	}
//	try
//	{
//		v1.update(t1, t3_new);
//		assert(false);
//	}
//	catch (std::exception &exp)
//	{
//		assert(true);
//	}
//	
//	v1.update(t3, t3_new);
//	Tutorial * elems = v1.get_elems();
//	for (int i = 0; i < v1.get_size(); i++)
//		if (elems[i] == t3)
//			assert(elems[i] == t3_new);
//	Tutorial t_got = v1.get_el(t3);
//	assert(t_got == t3_new);
//	try
//	{
//		v1.get_el(t1);
//		assert(false);
//	}
//	catch (std::exception &exp)
//	{
//		assert(true);
//	}
//
//}
//
//
//void test_Tutorial()
//{
//	Duration d1{ 11, 57 };
//	assert(d1.get_min() == 11);
//	assert(d1.get_sec() == 57);
//	Duration d{};
//	Tutorial t1{ "Function Pointers in C/C++","mycodeacademy",d1,2000, "https://www.youtube.com/watch?v=ynYtgGUNelE" };
//
//	assert(t1.get_title() == "Function Pointers in C/C++");
//	assert(t1.get_presenter() == "mycodeacademy");
//	assert(t1.get_duration() == d1);
//	assert(t1.get_likes() == 2000);
//	assert(t1.get_link() == "https://www.youtube.com/watch?v=ynYtgGUNelE");
//	std::stringstream out_t, out_d1, out_d2,out_d3,out_d4;
//	std::string s;
//	out_t << t1;
//	out_d1 << d1;
//	s = "Function Pointers in C/C++";
//	s += "\n\t by ";
//	s += "mycodeacademy";
//	s += "\n\t duration : ";
//	//s += out_d;
//	s += "11:57";
//	s += "\n\t likes: ";
//	s += "2000";
//	//s += "\n\t link: ";
//	//s += "https://www.youtube.com/watch?v=ynYtgGUNelE";
//	s += "\n";
//	assert(out_t.str() == s);
//	assert(out_d1.str() == "11:57");
//	Duration d2{ 1,2 }, d3{ 3,45 }, d4{ 14,5 };
//	out_d2 << d2;
//	assert(out_d2.str() == "01:02");
//	out_d3 << d3;
//	out_d4 << d4;
//	assert(out_d3.str() == "03:45");
//	assert(out_d4.str() == "14:05");
//	t1.plus_like();
//	assert(t1.get_likes() == 2001);
//	//t1.play();
//
//	//std::cout << t1 << d1;
//
//
//}
//
//void test_Repository()
//{
//	Duration d1{ 11, 57 };
//	Duration d2{ 40,24 };
//	Duration d3{ 70,30 };
//	Duration d3_new{ 70,32 };
//	Tutorial t1{ "Function Pointers in C/C++","mycodeacademy",d1,2000, "https://www.youtube.com/watch?v=ynYtgGUNelE" };
//	Tutorial t2{ "C++ Tutorial 10 : Object Oriented Programming","Derek Banas",d2, 844,"https://www.youtube.com/watch?v=ZOKLjJF54Xc" };
//	Tutorial t3{ "C++ Programming", "Derek Banas", d3, 49000,"https://www.youtube.com/watch?v=Rub-JsjMhWY" };
//	Tutorial t3_new{ "C++ Programming", "Derek Banas", d3_new, 49000,"https://www.youtube.com/watch?v=Rub-JsjMhWY" };
//
//	std::vector<Tutorial> v{};
//	std::vector<Tutorial> w{};
//	Repository repo{ v,w };
//	
//	repo.add(t1);
//	assert(repo.get_size_repo() == 1);
//	repo.add(t2);
//	assert(repo.get_size_repo() == 2);
//	repo.add(t3);
//	assert(repo.get_size_repo() == 3);
//	try
//	{
//		repo.add(t1);
//		assert(false);
//
//	}
//	catch (std::exception &exc)
//	{
//		//cout << exc.what();
//		assert(true);
//
//	}
//
//	assert(repo.get_size_repo() == 3);
//
//	repo.remove(t1);
//	assert(repo.get_size_repo() == 2);
//
//	try
//	{
//		repo.remove(t1);
//		assert(false);
//	}
//	catch (std::exception &exc)
//	{
//		assert(true);
//	}
//
//
//	try
//	{
//		repo.update(t1, t3_new);
//		assert(false);
//	}
//	catch (std::exception &exp)
//	{
//		assert(true);
//	}
//
//	repo.update(t3, t3_new);
//	std::vector<Tutorial> elems = repo.get_tutorials();
//	for (int i = 0; i < repo.get_size_repo(); i++)
//		if (elems[i] == t3)
//			assert(elems[i] == t3_new);
//
//	Tutorial t_got = repo.get_tutorial(t3);
//	assert(t_got == t3_new);
//	try
//	{
//		repo.get_tutorial(t1);
//		assert(false);
//	}
//	catch (std::exception &exp)
//	{
//		assert(true);
//	}
//
//
//	repo.add_watch_list(t2);
//	assert(repo.get_size_watch() == 1);
//	std::vector<Tutorial> watch = repo.get_watch_list();
//	assert(t2 == watch[0]);
//	repo.like_first_watch_list();
//	repo.delete_first_watch_list();
//	assert(repo.get_size_watch() == 0);
//}
//
//void test_Controller()
//{
//	/*Duration d1{ 11, 57 };
//	Duration d2{ 40,24 };*/
//	Duration d3{ 70,30 };
//	Duration d3_new{ 70,32 };
//	//Tutorial t1{ "Function Pointers in C/C++","mycodeacademy",d1,2000, "https://www.youtube.com/watch?v=ynYtgGUNelE" };
//	//Tutorial t2{ "C++ Tutorial 10 : Object Oriented Programming","Derek Banas",d2, 844,"https://www.youtube.com/watch?v=ZOKLjJF54Xc" };
//	Tutorial t3{ "C++ Programming", "Derek Banas", d3, 49000,"https://www.youtube.com/watch?v=Rub-JsjMhWY" };
//	Tutorial t3_new{ "C++ Programming", "Derek Banas", d3_new, 49000,"https://www.youtube.com/watch?v=Rub-JsjMhWY" };
//
//	std::vector<Tutorial> v{};
//	std::vector<Tutorial> w{};
//	Repository repo{ v,w };
//	Controller c{ repo };
//
//	c.add("Function Pointers in C/C++", "mycodeacademy", 11,57, 2000, "https://www.youtube.com/watch?v=ynYtgGUNelE");
//	assert(c.get_size_repo() == 1);
//	c.add("C++ Tutorial 10 : Object Oriented Programming", "Derek Banas", 40,54, 844, "https://www.youtube.com/watch?v=ZOKLjJF54Xc");
//	assert(c.get_size_repo() == 2);
//	c.add("C++ Programming", "Derek Banas", 70,30, 49000, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
//	assert(c.get_size_repo() == 3);
//	try
//	{
//		c.add("Function Pointers in C/C++", "mycodeacademy", 11, 57, 2000, "https://www.youtube.com/watch?v=ynYtgGUNelE");
//		assert(false);
//
//	}
//	catch (std::exception &exc)
//	{
//		//cout << exc.what();
//		assert(true);
//
//	}
//	try
//	{
//		c.add(" ", " ", -1, -1, -1, " ");
//		assert(false);
//	}
//	catch (std::exception &exc)
//	{
//		assert(true);
//	}
//
//	assert(c.get_size_repo() == 3);
//
//	c.remove("Function Pointers in C/C++");
//	assert(repo.get_size_repo() == 2);
//
//	try
//	{
//		c.remove(" ");
//		assert(false);
//	}
//	catch (std::exception &exc)
//	{
//		assert(true);
//	}
//
//
//	try
//	{
//		c.update("Function Pointers in C/C++", "Derek Banas", 70, 32, 49000, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
//		assert(false);
//	}
//	catch (std::exception &exp)
//	{
//		assert(true);
//	}
//
//	c.update("C++ Programming", "", 0, 0, 0, "");
//	std::vector<Tutorial> elems = c.get_all_repo();
//	for (int i = 0; i < c.get_size_repo(); i++)
//		if (elems[i] == t3)
//			assert(elems[i] == t3);
//
//	c.update("C++ Programming", "Derek Banas", 70, 30, 49001, "https://www.youtube.com/watch?v=Rub-JsjMhWY");
//	std::string presenter = "";
//	std::vector<Tutorial> watch = c.filter_by_presenter(presenter);
//	assert(watch.size()  == 2);
//	watch = c.filter_by_presenter("a");
//	assert(watch.size() == 0);
//
//	c.add_watch_list(t3);
//	assert(c.get_size_watch() == 1);
//	c.like_first_watch_list();
//	std::vector<Tutorial> all_watch = c.get_all_watch();
//	assert(all_watch[0] == t3);
//	c.delete_first_watch_list();
//
//
//
//}
//
//void test_all()
//{
//	/*test_DynamicVector();
//	test_Tutorial();
//	test_Repository();
//	test_Controller();*/
//}
