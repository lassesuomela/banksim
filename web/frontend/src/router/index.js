import Vue from 'vue'
import VueRouter from 'vue-router'
import LoginComponent from "../views/login.vue"
import SecureComponent from "../views/secure.vue"
import AboutComponent from "../views/About.vue"
import RegisterComponent from "../views/register.vue"



Vue.use(VueRouter)



const routes = [
    {
        path: '/',
        redirect: {
            name: "login"
        }
    },
    {
        path: "/login",
        name: "login",
        component: LoginComponent
        
    },
    {
        path: "/secure",
        name: "secure",
        component: SecureComponent
    },
    {
        path: "/about",
        name: "about",
        component: AboutComponent
    },
    {
        path: "/register",
        name: "register",
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