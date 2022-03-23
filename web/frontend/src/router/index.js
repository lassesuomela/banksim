import { createRouter, createWebHistory } from 'vue-router'
import Home from '../views/Home.vue'
import Login from "../views/Login.vue"



const routes = [
  {
    path: '/',
    name: 'home',
    component: Home,
    meta:{
      title: "Home"
    }
  },
  {
    path: '/login',
    name: 'Login',
    component: Login,
    meta:{
      title: "Login"
    }
  }
]

const router = createRouter({
  history: createWebHistory(process.env.BASE_URL),
  routes
})

router.beforeEach((to,from,next)=>{
  document.title = `${to.meta.title}`;
  next();
});

export default router

