
// 构建者模式 
// 以逐步的方法来创建对象，初始化一个建造者并让他为你创建一个对象，而不是直接构建一个对象，
// 对于需要多个构建函数参数的对象初始化特别有用，特别是这些参数的类型相同或相似时
	

#include<iostream>

public class Windows {
    public Window(boolean visable, boolean modal, boolean dialog){
        this.visable = visable;
        this.modal = modal;
        this.dialog = dialog;
    }

    private boolean visable;
    private boolean modal;
    private boolean dialog;
}


public class WindowsBuilder {
    public WindowsBuilder() {}

    public WindowsBuilder setDialog(boolean flag) {
        dialog = falg;
        return this;
    }

    public WindowsBuilder setModal(boolean flag) {
        modal = falg;
        return this;
    }

    public WindowsBuilder setVisable(boolean flag) {
        visable = falg;
        return this;
    }

    public Window build() {
        return new Windows( visable, modal, dialog);
    }

    private boolean dialog;
    private boolean visable;
    private boolean modal;
}

// 初始化对象实例
Windows w = new WindowsBuilder().setVisable(false).setModal(true).setDialog(true).build();