import Vue from 'vue'
import VueRouter from 'vue-router'
import LoginComponent from "../views/login.vue"
import HomeComponent from "../views/home.vue"
import RegisterComponent from "../views/register.vue"

Vue.use(VueRouter)

const routes = [
    {
        path: '/',
        redirect: "login"
    },
    {
        path: "/login",
        name: "Login",
        component: LoginComponent
        
    },
    {
        path: "/home",
        name: "Home",
        component: HomeComponent
    },
    {
        path: "/register",
        name: "Register",
        component: RegisterComponent
    }
  ]
  
  const router = new VueRouter({
    mode: 'history',
    base: process.env.BASE_URL,
    routes
  })
  
  router.beforeEach((to, from, next) => {
    document.title = `${to.name}`;
    next();
  });
  
  export default router
  